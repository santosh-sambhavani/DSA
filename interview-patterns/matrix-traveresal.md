![image](https://assets.leetcode.com/uploads/2021/06/08/waterflow-grid.jpg)

417. Pacific Atlantic Water Flow
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
```python3
from collections import deque
from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        if not heights or not heights[0]:
            return []
            
        rows, cols = len(heights), len(heights[0])
        
        def bfs(starts: set) -> set:
            # Using deque is vastly faster than queue.Queue in single-threaded Python
            queue = deque(starts)
            visited = set(starts)
            
            directions = ((0, -1), (-1, 0), (0, 1), (1, 0))
            
            while queue:
                row, col = queue.popleft()
                
                for dr, dc in directions:
                    newR, newC = row + dr, col + dc
                    # Boundary check + visited check
                    if 0 <= newR < rows and 0 <= newC < cols and (newR, newC) not in visited:
                        # Water flows to lower or equal height, meaning we can climb up
                        if heights[newR][newC] >= heights[row][col]:
                            visited.add((newR, newC))
                            queue.append((newR, newC))
            return visited

        # Generate ocean boundary sets using set comprehensions
        pacific_starts = {(r, 0) for r in range(rows)} | {(0, c) for c in range(cols)}
        atlantic_starts = {(r, cols - 1) for r in range(rows)} | {(rows - 1, c) for c in range(cols)}
        
        # Run independent BFS scans
        pacific_reachable = bfs(pacific_starts)
        atlantic_reachable = bfs(atlantic_starts)
        
        # Find intersection and map coordinates directly to lists
        return [list(coord) for coord in pacific_reachable if coord in atlantic_reachable]
```
