# 215. Kth Largest Element in an Array
# Example 1:
# Input: nums = [3,2,1,5,6,4], k = 2
# Output: 5
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_heap = []

        count = 0
        for num in nums:
            if count < k:
                heapq.heappush(min_heap, num)
                count += 1
            
            elif num > min_heap[0]:
                    heapq.heappush(min_heap, num)
                    heapq.heappop(min_heap)
            
        return min_heap[0]

# ----------------------------------------------------------------------------------------------------------------------------------------
# 347. Top K Frequent Elements
# Example 1:
# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]

import heapq
class Solution:
    def addToMap(self, map, num):
        if num in map:
            map[num] += 1
        else:
            map[num] = 1

    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m1 = {}
        for num in nums:
            self.addToMap(m1, num)

        m2 = {}
        min_heap = []
        count = 0
        for key in m1:
            freq = m1[key]
            if freq in m2:
                m2[freq].append(key)
            else:
                m2[freq] = [key]

            if count < k:
                heapq.heappush(min_heap, freq)
                count += 1
            elif freq > min_heap[0]:
                heapq.heappush(min_heap, freq)
                heapq.heappop(min_heap)

        visited = {}
        response = []
        for freq in min_heap:
            if freq not in visited:
                response += m2[freq]
                visited[freq] = True

        return response
# ----------------------------------------------------------------------------------------------------------------------------------------
# 373. Find K Pairs with Smallest Sums
# Example 1:
# Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
# Output: [[1,2],[1,4],[1,6]]
# Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

import heapq
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        min_heap = []
        heapq.heappush(min_heap, (nums1[0] + nums2[0], 0, 0))
        response = []
        len1 = len(nums1)
        len2 = len(nums2)
        hashSet = set()
        hashSet.add((0, 0))

        while k:
            _, i, j = heapq.heappop(min_heap)
            response.append([nums1[i], nums2[j]])

            if i+1 < len1 and (i+1, j) not in hashSet:
                heapq.heappush(min_heap, (nums1[i+1] + nums2[j], i+1, j))
                hashSet.add((i+1, j))
            
            if j+1 < len2 and (i, j+1) not in hashSet:
                heapq.heappush(min_heap, (nums1[i] + nums2[j+1], i, j+1))
                hashSet.add((i, j+1))

            k -= 1

        return response

