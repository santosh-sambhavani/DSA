# 210. Course Schedule II
# Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
# Output: [0,2,1,3]
# Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
# So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
# Also for some test cases need to check if there is cycle then it is not possible
class Solution:
    def isCycle(self, preqMap, alreadyProcessed, course, currentProcessingPath, path):
        if course in currentProcessingPath:
            return True
        if course in alreadyProcessed:
            return False
        currentProcessingPath.add(course)
        alreadyProcessed.add(course)

        if course in preqMap:
            for preReqCourse in preqMap[course]:
                if self.isCycle(preqMap, alreadyProcessed, preReqCourse, currentProcessingPath, path): 
                    return True
        
        currentProcessingPath.discard(course)
        path.append(course)

    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        preqMap = {}
        path = []

        for prereq in prerequisites:
            targetCourse = prereq[0]
            preReq = prereq[1]
            if targetCourse in preqMap:
                preqMap[targetCourse].append(preReq)
            else :
                preqMap[targetCourse] = [preReq]

        alreadyProcessed = set()
        for course in range(numCourses):
            if course not in alreadyProcessed:
                if self.isCycle(preqMap, alreadyProcessed, course, set(), path): return []

        return path

# 200. Number of Islands
# Example 1:
# Input: grid = [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
# Output: 1
# Example 2:
# Input: grid = [
#   ["1","1","0","0","0"],
#   ["1","1","0","0","0"],
#   ["0","0","1","0","0"],
#   ["0","0","0","1","1"]
# ]
# Output: 3
class Solution:
    def travelIsland(
        self, 
        grid: List[List[str]], 
        row: int, 
        col: int, 
        totalRows: int, 
        totalCols: int
    ):
        grid[row][col] = '0'
        if row-1 >= 0 and grid[row-1][col] == '1':
            self.travelIsland(grid, row-1, col, totalRows, totalCols)
        if row+1 < totalRows and grid[row+1][col] == '1':
            self.travelIsland(grid, row+1, col, totalRows, totalCols)
        if col-1 >= 0 and grid[row][col-1] == '1':
            self.travelIsland(grid, row, col-1, totalRows, totalCols)
        if col+1 < totalCols and grid[row][col+1] == '1':
            self.travelIsland(grid, row, col+1, totalRows, totalCols)

    def numIslands(self, grid: List[List[str]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        count = 0

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == '1':
                    count += 1
                    self.travelIsland(grid, row, col, rows, cols)
        
        return count
