# 643. Maximum Average Subarray I
# Input: nums = [1,12,-5,-6,50,3], k = 4
# Output: 12.75000
# Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        sum = 0
        length = len(nums)
        for i in range(0, k):
            sum += nums[i]
        
        answer = sum
        for i in range(k, length):
            sum = sum - nums[i-k] + nums[i]
            if sum > answer:
                answer = sum
        
        return float(answer / k)

# 3. Longest Substring Without Repeating Characters
# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        map = {s[0]: 0}
        left = 0
        right = 1
        maxLen = 1
        n = len(s)

        while right < n:
            if s[right] in map:
                currLeft = left
                left = map[s[right]] + 1
                for i in range(currLeft, left):
                    del map[s[i]]
            else :
                currLen = (right - left) + 1
                if currLen > maxLen:
                    maxLen = currLen
            map[s[right]] = right
            right += 1

        return maxLen

# # Leetocde 76. Minimum Window Substring
# Input: s = "ADOBECODEBANC", t = "ABC"
# Output: "BANC"
# Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
class Solution:
    def addToMap(self, m, ch):
        if ch in m:
            m[ch] += 1
        else :
            m[ch] = 1

    def mapMatches(self, m1, m2):
        for key in m2:
            if key not in m1:
                return False
            elif m1[key] < m2[key]:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:
        m1 = {}
        m2 = {}
        left = 0
        len1 = len(s)
        minStr = ""

        for ch in t:
            self.addToMap(m2, ch)
        
        for right in range(0, len1):
            self.addToMap(m1, s[right])

            while self.mapMatches(m1, m2):
                currStr = s[left:right+1]
                if minStr == "":
                    minStr = currStr
                elif len(minStr) > len(currStr):
                    minStr = currStr
                m1[s[left]] -= 1
                left += 1
                        
        return minStr

