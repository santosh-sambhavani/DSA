## 2PC commit in microservices 

In microservices, the standard rule is **Database-per-Service**. When a single business action must update data across multiple microservice databases simultaneously, you face a core distributed systems problem: **How do you guarantee that either all microservices update their databases or none do?**

This is where 2PC is used. While distributed locking prevents race conditions, **Two-Phase Commit (2PC)** acts as a distributed transaction manager across microservice databases to guarantee **Atomicity (All-or-Nothing)**.

---

### Real Microservices Scenario: Order & Inventory Management

Consider an e-commerce platform where the **Order Service** and **Inventory Service** each have their own isolated PostgreSQL databases.

```
       [ Client: "Place Order" ]
                  │
                  ▼
      ┌────────────────────────┐
      │ Transaction Coordinator│
      │ (e.g., Narayana / Atomikos)
      └───────────┬────────────┘
                  │
        ┌─────────┴─────────┐
        ▼                   ▼
┌───────────────┐   ┌─────────────────┐
│ Order Service │   │Inventory Service│
│  (Postgres A) │   │  (Postgres B)   │
└───────────────┘   └─────────────────┘

```

#### Phase 1: Prepare Phase (Voting & Locking)

1. The **Coordinator** receives the request to place an order.
2. It sends a `PREPARE` request over the network to both services:
* **Order Service:** Begins a local transaction, writes `INSERT INTO orders (id, status) VALUES (101, 'PENDING')`, locks the row, and responds **"READY"**.
* **Inventory Service:** Begins a local transaction, writes `UPDATE inventory SET stock = stock - 1 WHERE item_id = 42`, locks the inventory row, and responds **"READY"**.


3. At this stage, neither database has committed the changes, but **both rows remain locked against reads/writes by other processes**.

#### Phase 2: Commit or Abort Phase (Execution)

* **Success Path (Both Vote "READY"):**
* Coordinator writes a commit log to disk and sends `GLOBAL_COMMIT` to both services.
* Both services execute `COMMIT` locally, release their database locks, and respond **"ACK"**.
* The order is placed, and stock is decremented atomically.


* **Failure Path (e.g., Inventory Out of Stock / Network Timeout):**
* Inventory Service finds `stock = 0` and responds **"ABORT"**.
* Coordinator sends `GLOBAL_ROLLBACK` to both services.
* Order Service executes `ROLLBACK`, discarding the inserted order and releasing its row lock.



---

### Why 2PC Is an Anti-Pattern in Modern Microservices

While 2PC provides strict ACID consistency across services, it introduces severe operational drawbacks:

* **Synchronous Blocking:** Database rows in both services remain locked for the entire duration of the network round-trips. If the network hiccups, other transactions waiting on those rows pile up, leading to thread starvation.
* **Single Point of Failure (Coordinator):** If the coordinator crashes after receiving "READY" votes in Phase 1, participating databases cannot decide on their own whether to commit or abort. They hold their locks indefinitely until the coordinator recovers.
* **Technology Lock-In:** Requires every database engine in your architecture to support the **XA Standard** (two-phase commit protocol). Many modern NoSQL databases (MongoDB, DynamoDB, Cassandra) and message brokers do not support XA transactions.

This high latency, vulnerability to outages, and lack of support for external third-party APIs is the exact reason microservices architectures generally abandon 2PC and adopt the **Saga pattern** (eventual consistency with compensating transactions) instead.

---

## Saga Pattern:

The **Saga pattern** exists to solve the problem of maintaining data consistency across multiple distributed services without using distributed database locks.

In a microservices architecture with a database-per-service model, a single business transaction often spans multiple independent databases. Traditional ACID transactions rely on **Two-Phase Commit (2PC)** or distributed locking, which introduces critical issues:

* **Tight Coupling & Availability Bottlenecks:** If any service or network link lags, locks stay open, degrading performance across the entire system.
* **Incompatibility with External APIs:** Third-party services (e.g., Stripe, PayPal, external logistics) do not support XA/2PC protocols.
* **Deadlocks & Latency:** Holding database locks across network boundaries kills throughput.

The Saga pattern replaces global locks by breaking a long-running transaction into a sequence of **local transactions**. Each step updates local storage and publishes an event/message; if a step fails, the Saga executes **compensating transactions** in reverse order to semantically undo preceding changes.

---

### Real Scenario: Online Travel Aggregator (Flight + Hotel + Car Rental)

Consider a travel aggregator like Expedia, Skyscanner, or Booking.com offering a single **"Vacation Package Checkout"** containing a flight booking, hotel reservation, and rental car.

```
[Customer Pays & Books Package]
        │
        ├── Step 1: Charge Card via Stripe API
        ├── Step 2: Book Seat via Airline API (Sabre / Amadeus GDS)
        ├── Step 3: Reserve Room via Marriott/Hilton API
        └── Step 4: Reserve Vehicle via Hertz/Avis API

```

#### Why There Is No Better Alternative Than a Saga

1. **Third-Party APIs Cannot Be Locked (2PC / Distributed ACID is impossible):**
* Airlines, payment gateways, and hotel chains expose distinct REST/SOAP APIs on completely separate infrastructures.
* You cannot hold a database lock across Stripe's servers, an airline's mainframe, and a hotel's property management system while waiting for other calls to finish.


2. **Long-Running Latency:**
* Airline seat confirmation or payment processing can take 2 to 10 seconds. Holding global database connections or transaction threads for this duration causes connection pool exhaustion and system-wide outages.


3. **Asymmetric Failures Require Explicit Semantic Compensation:**
* If Step 1 (Payment) succeeds, Step 2 (Flight) succeeds, but Step 3 (Hotel) fails due to zero vacancy:
* A simple database rollback does not exist in external systems.
* The Saga orchestrator steps in and executes compensating transactions:
1. Cancel the Flight Reservation via the Airline API.
2. Refund the Customer via Stripe API.
3. Mark the travel itinerary state as `FAILED_HOTEL_UNAVAILABLE`.







| Pattern / Alternative | Why It Fails in This Scenario |
| --- | --- |
| **Two-Phase Commit (2PC / XA)** | Requires all participants to support distributed locks. External third parties (Stripe, Airlines) do not implement XA. |
| **Monolithic Single Database** | Violates microservice boundaries, cannot integrate external third-party inventory APIs into a single DB engine. |
| **Simple Synchronous Try/Catch HTTP** | If the orchestrator server crashes halfway through after charging money, state is permanently lost without a persistent log of compensating actions. |

In cross-domain, multi-organization, or high-latency workflows where external APIs must be coordinated reliably, the Saga pattern (implemented either via an **Orchestrator** like Temporal/AWS Step Functions or **Choreography** via message brokers like Kafka) is the standard architectural choice.
