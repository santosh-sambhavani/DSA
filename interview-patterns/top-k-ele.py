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

