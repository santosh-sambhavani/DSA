Certainly! Here's a step-by-step explanation of the **Permutations and Combinations (PNC) approach** for the problem of distributing **n candies** among **3 children** with a limit on how many candies each child can get.

---

### Problem Recap:
- You have **n candies**.
- You want to distribute them among **3 children**.
- Each child can get **at most `limit` candies**.
- Find the total number of ways to do this.

---

## Step 1: Total ways to distribute candies without any limit

Distributing **n candies** among 3 children (where candies are identical) is a classic **stars and bars** problem.

- The formula for distributing `n` identical items into `k` bins is:

  $$
  \binom{n + k - 1}{k - 1}
  $$

- Here, \( k = 3 \), so total ways without limit:

  $$
  \binom{n + 3 - 1}{3 - 1} = \binom{n + 2}{2}
  $$

---

## Step 2: Subtract ways violating the limit condition

We need to exclude distributions where **any child gets more than `limit` candies**.

- Define \( L = \text{limit} \).

- Use **Inclusion-Exclusion Principle**:

  - Subtract ways where **at least one child** gets \( > L \) candies.
  - Add back ways where **at least two children** get \( > L \) candies (because they were subtracted twice).
  - Subtract ways where **all three children** get \( > L \) candies.

---

## Step 3: Calculate violating cases

### Case 1: One child gets more than \( L \)

- Suppose child 1 gets \( L + 1 \) candies or more.
- Set aside \( L + 1 \) candies for child 1.
- Remaining candies to distribute among 3 children:

  $$
  n - (L + 1)
  $$

- Number of ways to distribute remaining candies among 3 children (no limit now):

  $$
  \binom{(n - (L + 1)) + 3 - 1}{3 - 1} = \binom{n - L + 1}{2}
  $$

- Since any of the 3 children can be the one violating, multiply by 3:

  $$
  3 \times \binom{n - L + 1}{2}
  $$

### Case 2: Two children get more than \( L \)

- Suppose child 1 and child 2 both get at least \( L + 1 \) candies.
- Set aside \( 2 \times (L + 1) \) candies.
- Remaining candies:

  $$
  n - 2(L + 1)
  $$

- Number of ways to distribute remaining candies among 3 children:

  $$
  \binom{n - 2L}{2}
  $$

- Number of ways to choose which 2 children violate:

  $$
  \binom{3}{2} = 3
  $$

- Total ways:

  $$
  3 \times \binom{n - 2L}{2}
  $$

### Case 3: All three children get more than \( L \)

- Set aside \( 3 \times (L + 1) \) candies.
- Remaining candies:

  $$
  n - 3(L + 1)
  $$

- Number of ways:

  $$
  \binom{n - 3L - 1}{2}
  $$

- Only 1 way to choose all 3 children.

---

## Step 4: Final formula using Inclusion-Exclusion

$$
\text{Total valid ways} = \binom{n + 2}{2} - 3 \binom{n - L + 1}{2} + 3 \binom{n - 2L}{2} - \binom{n - 3L - 1}{2}
$$

- Treat any binomial coefficient with negative or invalid values as 0.

---

## Example:

- \( n = 7 \) candies
- \( L = 3 \) candies limit per child

Calculate:

- Total ways: \(\binom{7 + 2}{2} = \binom{9}{2} = 36\)
- One child violates: \(3 \times \binom{7 - 3 + 1}{2} = 3 \times \binom{5}{2} = 3 \times 10 = 30\)
- Two children violate: \(3 \times \binom{7 - 2 \times 3}{2} = 3 \times \binom{1}{2} = 0\) (since \(\binom{1}{2} = 0\))
- Three children violate: \(\binom{7 - 3 \times 3 - 1}{2} = \binom{-3}{2} = 0\)

Final ways:

$$
36 - 30 + 0 - 0 = 6
$$

---

### Summary:

- Use **stars and bars** for total distributions.
- Use **Inclusion-Exclusion** to subtract invalid distributions.
- Calculate binomial coefficients carefully.
- This approach is **O(1)** time complexity.

---


## "Stars and Bars" theorem:
Certainly! The formula 

$$
\binom{n + k - 1}{k - 1}
$$

is called the **"Stars and Bars" theorem** in combinatorics. It counts the number of ways to distribute **n identical items** into **k distinct bins** (or groups), where bins can be empty.

---

## Explanation with a simple example:

### Problem:
Distribute **5 identical candies** among **3 children**. How many ways can this be done?

---

### Step 1: Understand the problem

- Candies are identical (indistinguishable).
- Children are distinct (Child 1, Child 2, Child 3).
- Each child can get zero or more candies.

---

### Step 2: Visualize using stars and bars

- Represent each candy as a **star**: `*`
- Use **bars** to separate candies into bins (children).

For example:

```
**|*|**
```

Means:

- Child 1 gets 2 candies
- Child 2 gets 1 candy
- Child 3 gets 2 candies

---

### Step 3: How many symbols?

- Total stars = 5 (candies)
- Total bars = 2 (to separate 3 children, you need k-1 bars)

---

### Step 4: Arrange stars and bars

- Total positions = stars + bars = 5 + 2 = 7
- We need to choose positions for either bars or stars.

Number of ways = number of ways to choose positions of bars among these 7 positions:

$$
\binom{7}{2} = 21
$$

Or equivalently, choose positions of stars:

$$
\binom{7}{5} = 21
$$

---

### Step 5: General formula

For distributing \( n \) identical items into \( k \) bins:

- Total symbols = \( n + k - 1 \)
- Choose positions for \( k-1 \) bars:

$$
\binom{n + k - 1}{k - 1}
$$

---

### Summary:

- **Stars** = identical items
- **Bars** = separators between bins
- Number of ways = ways to place bars among stars and bars combined

---

## Explaination for distributing candies with violated rule

This is why the stars and bars formula is applied again with \(n - (L + 1)\) candies and 3 children.

When we say **child 1 gets \(L + 1\) candies or more**, we have already allocated those candies to child 1.

Now, the **remaining candies** are:

$$
n - (L + 1)
$$

These remaining candies need to be distributed **among all 3 children again**, but with the condition that child 1 has already received at least \(L + 1\) candies.

---

### Why distribute among 3 children again, not just 2?

- The **distribution variables** represent how many candies each child gets.
- We fixed child 1's candies to be at least \(L + 1\), but child 1 **can still get more candies** from the remaining ones.
- So, the remaining candies can be given to **child 1, child 2, or child 3**.

---

### In other words:

- We set aside \(L + 1\) candies for child 1 to ensure the violation.
- But child 1 can get **more than** \(L + 1\) candies.
- So, the leftover candies are distributed among **all three children**, including child 1.

---

### Example:

- \(n = 7\), \(L = 3\)
- Child 1 gets at least 4 candies (\(L+1 = 4\))
- Remaining candies: \(7 - 4 = 3\)
- These 3 candies can be given to child 1, 2, or 3 in any way.
