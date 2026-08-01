743. Network Delay Time
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```
from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        # Build adjacency list: node -> list of (neighbor, weight)
        graph = defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))

        # Min-heap to store (cumulative_time, node)
        pq = [(0, k)]
        
        # Track minimum time to reach each node
        distances = {i: float('inf') for i in range(1, n + 1)}
        distances[k] = 0

        while pq:
            curr_time, u = heapq.heappop(pq)

            # Skip outdated entries in the heap
            if curr_time > distances[u]:
                continue

            for v, weight in graph[u]:
                new_time = curr_time + weight
                if new_time < distances[v]:
                    distances[v] = new_time
                    heapq.heappush(pq, (new_time, v))

        max_time = max(distances.values())
        return max_time if max_time < float('inf') else -1
```
----
![image](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

778. Swim in Rising Water
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
```
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        pq = [(grid[0][0], 0, 0)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        seen = set()
        
        while pq:
            maxHeight, r, c = heapq.heappop(pq)
            if (r, c) in seen: continue
            seen.add((r, c))
            if r == m-1 and c == n-1:
                return maxHeight
            
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in seen:
                    newHeight = max(maxHeight, grid[nr][nc])
                    heapq.heappush(pq, (newHeight, nr, nc))
        
        return -1
```
---

![](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png)

Leetcode 787. Cheapest Flights Within K Stops
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

### 1D Array solution 
```
from collections import defaultdict
import heapq

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dest: int, k: int) -> int:
        # Build adjacency list: node -> list of (neighbor, cost)
        graph = defaultdict(list)
        for u, v, w in flights:
            graph[u].append((v, w))

        # Min-heap to store (cumulative_cost, stops, node)
        pq = [(0, 0, src)]
        
        # Track minimum stops to reach each node
        min_stops = {i: float('inf') for i in range(0, n + 1)}

        while pq:
            curr_cost, curr_stops, curr_node = heapq.heappop(pq)

            # print(f"curr_node: {curr_node}, curr_stops: {curr_stops}, curr_cost: {curr_cost}")

            if curr_node == dest:
                return curr_cost

            if curr_stops >= min_stops[curr_node] or curr_stops > k:
                continue
            
            min_stops[curr_node] = curr_stops

            for neighbour, neighbour_cost in graph[curr_node]:
                new_cost = curr_cost + neighbour_cost

                # print(f"neighbour: {neighbour}, new_cost: {new_cost}")

                newItem = (new_cost, curr_stops + 1, neighbour)
                heapq.heappush(pq, newItem)

        return -1
```

### 2D Array solution 
```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        // 2D distance tracking: dist[node][flights_taken]
        // Sized to k + 2 because max flights allowed = k + 1
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            if (u == dst) return cost;
            if (stops > k) continue;

            // Standard Dijkstra state evaluation optimized for 2D structures
            if (cost > dist[u][stops]) continue;

            for (auto& [v, wt] : adj[u]) {
                // Moving from 'u' with 'stops' flights to 'v' means we will have 'stops + 1' flights
                if (cost + wt < dist[v][stops + 1]) {
                    dist[v][stops + 1] = cost + wt;
                    pq.push({cost + wt, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
```

![](https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png)

Leetcode 1514. Path with Maximum Probability
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
```
from collections import defaultdict
import heapq

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], startNode: int, endNode: int) -> float:
        graph = defaultdict(list)
        for index in range(len(edges)):
            u, v = edges[index]
            w = succProb[index]
            graph[u].append((v, w))
            graph[v].append((u, w))
        
        visited = set()
        maxProb = {i: 0 for i in range(n)}
        pq = [(-1, startNode)] # priority queue with (probability, node)
        # as this is max heal we will store probabilities in negative

        while pq:
            currProb, currNode = heapq.heappop(pq)
            currProb = -currProb

            # print(f"currNode: {currNode}, currProb: {currProb}, neig: {graph[currNode]}")

            if currNode == endNode:
                return currProb

            if currProb < maxProb[currNode]:
                continue
            maxProb[currNode] = currProb
            visited.add(currNode)

            for neighbour, neighbourProb in graph[currNode]:
                newProb = currProb * neighbourProb
                if neighbour not in visited and maxProb[neighbour] < newProb:
                    heapq.heappush(pq, (-newProb, neighbour))

        return 0
```
