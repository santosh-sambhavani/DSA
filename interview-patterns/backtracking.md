leetcode 78. Subsets
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

```
class Solution:
    def solve(self, length: int, nums: List[int], index: int, prefix: List[int], results: List[List[int]]):
        for i in range(index, length):
            subset = prefix.copy()
            subset.append(nums[i])
            results.append(subset)
            self.solve(length, nums, i+1, subset, results)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        results = [[]]
        self.solve(len(nums), nums, 0, [], results)
        return results
```
---

Leetcode 46. Permutations
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

<img width="650" height="256" alt="Screenshot 2026-08-01 at 7 41 55 PM" src="https://github.com/user-attachments/assets/d2af0d32-1cd6-4252-a567-b4424f6a756f" />

```
class Solution:
    def swap(self, nums, i, j) -> List[int]:
        swapped = nums.copy()
        temp = swapped[i]
        swapped[i] = swapped[j]
        swapped[j] = temp
        return swapped

    def solve(self, nums: List[int], index: int, results: List[List[int]]) -> None:
        if index == len(nums) - 1:
            results.append(nums)
            return 
        
        for i in range(index, len(nums)):
            swapped = self.swap(nums, index, i)
            self.solve(swapped, index+1, results)

    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        self.solve(nums, 0, results)
        return results
```
---

<img width="322" height="242" alt="word2" src="https://github.com/user-attachments/assets/b5fd0f72-76d1-43a2-9d1f-ff54dc8ad470" />

Leetcode 79. Word Search
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

```
from collections import deque

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        rows, cols = len(board), len(board[0])
        visited = set()
        lengthOfWord = len(word)

        def dfs(row, col, searchIndex):
            directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
            
            if searchIndex == lengthOfWord:
                return True
            
            visited.add((row, col))
            for x, y in directions:
                newX, newY = row + x, col + y    
                if 0 <= newX < rows and 0 <= newY < cols and (newX, newY) not in visited and word[searchIndex] == board[newX][newY] and dfs(newX, newY, searchIndex + 1):
                    # print(f"curr: {row,col}, new: {(newX, newY)}, visited: {visited}")
                    return True

            visited.remove((row, col))
            return False

        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0] and dfs(i, j, 1):
                    return True
        
        return False
```
---
Leetcode 39. Combination Sum
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

<img width="1026" height="720" alt="Screenshot 2026-08-02 at 9 47 39 AM" src="https://github.com/user-attachments/assets/746ddcf8-728a-4032-bae3-5bb399b4f45e" />

```
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        length = len(candidates)
        results = []
        
        def dfs(index, nums, total):
            # print(f"nums: {nums}, index: {index}, total: {total}")
            if total == target:
                results.append(nums.copy())
                return

            if total > target or index == length:
                return
            
            curr = candidates[index]
            nums.append(curr)
            dfs(index, nums, total + curr)

            nums.pop()
            dfs(index+1, nums, total)
        
        dfs(0, [], 0)

        return results
```
---
51. N-Queens

```
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        results = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        colSet = set()
        posDiaSet = set()
        negDiaSet = set()

        def backtrack(row):
            if row == n:
                newRes = board.copy()
                newRes = ["".join(row) for row in newRes]
                results.append(newRes)
                return

            for col in range(n):
                if col in colSet or (row + col) in posDiaSet or (row - col) in negDiaSet:
                    continue
                
                board[row][col] = 'Q'
                colSet.add(col)
                posDiaSet.add((row + col))
                negDiaSet.add((row - col))

                backtrack(row + 1)

                board[row][col] = '.'
                colSet.remove(col)
                posDiaSet.remove((row + col))
                negDiaSet.remove((row - col))

        backtrack(0)
        return results
```
