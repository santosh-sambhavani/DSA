# 743. Network Delay Time
# Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
# Output: 2
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
