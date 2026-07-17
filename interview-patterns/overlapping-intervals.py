# 56. Merge Intervals
# Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x:x[0])
        merged = [intervals[0]]

        for i in range(1, len(intervals)):
            lastInterval = merged[-1]
            interval = intervals[i]

            if interval[0] <= lastInterval[1]:
                lastInterval[1] = max(lastInterval[1], interval[1])
            else:
                merged.append(interval)

        return merged

# 57. Insert Interval
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        combinedIntervals = []
        added = False
        for interval in intervals:
            if newInterval[0] <= interval[0]:
                combinedIntervals.append(newInterval)
                added = True
            combinedIntervals.append(interval)
        
        if not added:
            combinedIntervals.append(newInterval)
        
        merged = [combinedIntervals[0]]
        for i in range(1, len(combinedIntervals)):
            lastInterval = merged[-1]
            interval = combinedIntervals[i]

            if interval[0] <= lastInterval[1]:
                lastInterval[1] = max(lastInterval[1], interval[1])
            else:
                merged.append(interval)

        return merged

# 435. Non-overlapping Intervals
# Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
# Output: 1
# Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x:x[0])
        count = 0
        lastEnd = intervals[0][1]

        for i in range(1, len(intervals)):
            if lastEnd > intervals[i][0]:
                lastEnd = min(lastEnd, intervals[i][1])
                count += 1
            else:
                lastEnd = intervals[i][1]

        return count

# 452. Minimum Number of Arrows to Burst Balloons
# Input: points = [[10,16],[2,8],[1,6],[7,12]]
# Output: 2
# Explanation: The balloons can be burst by 2 arrows:
# - Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
# - Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

# Input: [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
# Output: 2
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x:x[0])
        count = 1
        
        prev = points[0]
        for i in range(1, len(points)):
            curr = points[i]

            if curr[0] > prev[1]:
                count += 1
                prev = curr
            else :
                prev = [max(curr[0], prev[0]), min(curr[1], prev[1])]
        
        return count
        
