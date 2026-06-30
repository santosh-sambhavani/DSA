# 560. Subarray Sum Equals K
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        hashMap = {0: 1}
        currSum = 0
        count = 0

        for i, n in enumerate(nums):
            currSum += n

            # If (currSum - k) has appeared before, then each occurrence represents
            # a previous prefix sum such that:
            #     currSum - previousPrefixSum = k
            # Every previous occurrence of (currSum - k) is a valid starting point
            # for a subarray ending at the current index whose sum is k.
            if currSum - k in hashMap:
                count += hashMap[currSum - k]

            if currSum in hashMap:
                hashMap[currSum] += 1
            else:
                hashMap[currSum] = 1
            
        
        return count

# leet code 525:
# # Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
# Example :
# Input: nums = [0,1,1,1,1,1,0,0,0]
# Output: 6
# Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        cum = nums
        maxLen = 0

        # Convert every 0 to -1 so that:
        # equal number of 0s and 1s => subarray sum becomes 0
        for i, n in enumerate(cum):
            if n == 0:
                cum[i] = -1

        # Maps prefix sum -> first index where it occurred.
        # Prefix sum 0 is considered to occur before the array starts
        # so subarrays starting from index 0 are handled correctly.
        hashMap = {0: -1}

        # Build prefix sum array.
        for i, n in enumerate(cum):
            if i == 0:
                continue
            cum[i] = cum[i - 1] + cum[i]

        for i, n in enumerate(cum):
            # Store only the first occurrence because it gives the
            # longest possible subarray for this prefix sum.
            if n not in hashMap:
                hashMap[n] = i
            else:
                # Same prefix sum seen before:
                # prefixSum[i] - prefixSum[previous] = 0
                # => the subarray between them has sum 0,
                # which means equal numbers of 0s and 1s.
                maxLen = max(maxLen, i - hashMap[n])

        return maxLen
