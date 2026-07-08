# Two Sum Problem leetcode 1
# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for i, n in enumerate(nums):
            map[n] = i

        for i, n in enumerate(nums):
            if (target - n) in map and map[target - n] != i:
                return [map[target - n], i]


# # Three Sum Problem leetcode 15
# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation: 
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
# Notice that the order of the output and the order of the triplets does not matter.
class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        response = []
        nums.sort()

        for i in range(0, len(nums) - 2):
            n = nums[i]
            left = i+1
            right = len(nums) - 1

            while left < right:
                sum = n + nums[left] + nums[right]
                if sum == 0:
                    response.append([n, nums[left], nums[right]])
                    left += 1
                    right -= 1
                elif sum < 0:
                    left += 1
                else:
                    right -= 1

        unique_tuples = set(tuple(item) for item in response)

        # Optional: Convert back to a list of lists if needed
        unique_lists = [list(item) for item in unique_tuples]

        return unique_lists

# # Two sum 2, input array is sorted leetcode 167
# Input: numbers = [2,7,11,15], target = 9
# Output: [1,2]
# Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        numbers.sort()

        while left < right:
            sum = numbers[left] + numbers[right]
            if sum < target:
                left += 1
            elif sum > target:
                right -= 1
            else:
                return [left+1, right+1]

