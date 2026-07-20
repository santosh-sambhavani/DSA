# leetocde 111. Minimum Depth of Binary Tree
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = [root]

        depth = 1
        while queue:
            for _ in range(len(queue)):
                currNode = queue.pop(0)
                if not currNode.left and not currNode.right:
                    return depth
                if currNode.left:
                    queue.append(currNode.left)
                if currNode.right:
                    queue.append(currNode.right)
            depth += 1

# Walls And Gates
from os import *
from sys import *
from collections import *
from math import *

INF = 2147483647
def wallsAndGates(grid, rows, cols): 
    queue = []
    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 0:
                queue.append((row, col))

    visited = set()
    while queue:
        currPos = queue.pop(0)
        x, y = currPos[0], currPos[1] 
        visited.add((x,y))
        if x-1 >= 0 and (x-1,y) not in visited and grid[x-1][y] == INF:
            grid[x-1][y] = grid[x][y] + 1
            queue.append((x-1, y))
        if x+1 < rows and (x+1,y) not in visited and grid[x+1][y] == INF:
            grid[x+1][y] = grid[x][y] + 1
            queue.append((x+1, y))
        if y-1 >= 0 and (x,y-1) not in visited and grid[x][y-1] == INF:
            grid[x][y-1] = grid[x][y] + 1
            queue.append((x, y-1))
        if y+1 < cols and (x,y+1) not in visited and grid[x][y+1] == INF:
            grid[x][y+1] = grid[x][y] + 1
            queue.append((x, y+1))
    
    return grid
'''
2147483647 -1 0 2147483647
2147483647 2147483647 2147483647 -1
2147483647 -1 2147483647 -1
0 -1 2147483647 2147483647

3 -1 2 1
2 2147483647 1 -1
1 -1 2 -1
0 -1 3 4

3 -1 0 1
2 2 1 -1
1 -1 2 -1
0 -1 3 4
'''






