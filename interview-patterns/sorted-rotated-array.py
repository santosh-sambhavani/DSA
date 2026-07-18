# 33. Search in Rotated Sorted Array
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
import math
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left <= right:
            mid = math.floor(left + ((right - left) / 2))

            if nums[mid] == target:
                return mid

            # if left part is sorted
            if nums[left] <= nums[mid]:
                # check if it lies in left
                if nums[left] <= target and nums[mid] > target:
                    right = mid - 1
                else :
                    left = mid + 1
            elif nums[mid] <= nums[right]: # else check if right part is sorted
                # check if it lies in right
                if nums[mid] < target and nums[right] >= target:
                    left = mid + 1
                else :
                    right = mid - 1

        return -1

# 153. Find Minimum in Rotated Sorted Array
# Input: nums = [3,4,5,1,2]
# Output: 1
# Explanation: The original array was [1,2,3,4,5] rotated 3 times.

import math
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        left = 0
        right = len(nums) - 1

        while left < right:
            mid = math.floor(left + ((right - left) / 2))

            if nums[mid] <= nums[right]:
                right = mid
            else:
                left = mid + 1
        
        return nums[left]

# 240. Search a 2D Matrix II
# Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
# Output: true
# Trick: start from top right corner
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i = 0
        j = len(matrix[0]) - 1
        totalRows = len(matrix)
        totalCols = len(matrix[0])

        while i < totalRows and j < totalCols and i >= 0 and j >= 0:
            currValue = matrix[i][j]
            if currValue == target:
                return True
            elif target > currValue:
                i += 1
            else: 
                j -= 1
        
        return False
