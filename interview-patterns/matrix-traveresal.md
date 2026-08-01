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
---

<img width="1053" height="653" alt="maxarea1-grid" src="https://github.com/user-attachments/assets/bcb796a6-04b2-4e22-a819-7ae4b009a65e" />

Leetcode 695. Max Area of Island
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
```
from queue import LifoQueue

class Solution:
    def traverse(self, grid, visited, currRow, currCol, rows, cols) -> int:
        stack = LifoQueue()
        stack.put((currRow, currCol))
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        area = 0
        while not stack.empty():
            top = stack.get()
            area += 1
            # print(f"top: {top}")
            
            for x, y in directions:
                currX, currY = top[0], top[1]
                newX, newY = currX + x, currY + y
                newCord = (newX, newY)

                if 0 <= newX < rows and 0 <= newY < cols and newCord not in visited and grid[newX][newY] == 1:
                    visited.add(newCord)
                    stack.put(newCord)
        
        return area


    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = set()
        rows, cols = len(grid), len(grid[0])
        maxArea = 0

        for i in range(rows):
            for j in range(cols):
                if (i, j) not in visited and grid[i][j] == 1:
                    visited.add((i, j))
                    # print(f"i, j = {(i, j)}")
                    maxArea = max(maxArea, self.traverse(grid, visited, i, j, rows, cols))
                    # print(f"maxArea = {maxArea}")

        return maxArea
```
