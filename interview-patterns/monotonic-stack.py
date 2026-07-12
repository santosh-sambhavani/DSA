# 496. Next Greater Element I
# Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
# Output: [-1,3,-1]
# Explanation: The next greater element for each value of nums1 is as follows:
# - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
# - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
# - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
class Solution:
    def top(self, stack: List[int]) -> int:
        if not stack:
            return None
        return stack[-1]

    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack = []
        nextGreaterElesNums2 = {}

        for i in range(len(nums2)):
            nextGreaterElesNums2[nums2[i]] = -1
            topElement = self.top(stack)
            while (topElement != None and nums2[i] > nums2[topElement]):
                nextGreaterElesNums2[nums2[topElement]] = nums2[i]
                stack.pop()
                topElement = self.top(stack)
            stack.append(i)

        response = []
        for num in nums1:
            response.append(nextGreaterElesNums2[num])
        
        return response

# Leetcode: 739. Daily Temperatures
# Given an array of integers temperatures represents the daily temperatures, 
# return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
# If there is no future day for which this is possible, keep answer[i] == 0 instead.
# Example:
# Input: temperatures = [73,74,75,71,69,72,76,73]
# Output: [1,1,4,2,1,1,0,0]
class Solution:
    def top(self, stack: List[int]) -> int:
        if not stack:
            return None
        return stack[-1]

    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        n = len(temperatures)
        response = [0] * n
        for i in range(n):
            topElement = self.top(stack)
            while (topElement != None and temperatures[i] > temperatures[topElement]):
                response[topElement] = i - topElement
                stack.pop()
                topElement = self.top(stack)
            stack.append(i)
        
        return response
 


