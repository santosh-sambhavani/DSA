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
