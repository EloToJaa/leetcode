# Category: algorithms
# Level: Medium
# Percent: 45.5194%



# You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
# 
# Two intervals are considered overlapping if they share at least one point.
# 
# Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
# 
# Return intervals after the insertion.
# 
# Note that you don't need to modify intervals in-place. You can make a new array and return it.
# 
#  
# Example 1:
# 
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
# 
# 
# Example 2:
# 
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
# 
# 
#  
# Constraints:
# 
# 
# 	0 <= intervals.length <= 10⁴
# 	intervals[i].length == 2
# 	0 <= starti <= endi <= 10⁵
# 	intervals is sorted by starti in ascending order.
# 	newInterval.length == 2
# 	0 <= start <= end <= 10⁵
# 
 

class Solution:
    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:
        if len(intervals) == 0:
            return [newInterval]

        start, end = newInterval
        new_intervals: list[list[int]] = []
        i = 0
        while i < len(intervals) and intervals[i][1] < start:
            l, r = intervals[i]
            new_intervals.append([l, r])
            i += 1
        
        if i < len(intervals):
            start = min(start, intervals[i][0])
        while i < len(intervals) and intervals[i][0] <= end:
            end = max(end, intervals[i][1])
            i += 1
        new_intervals.append([start, end])
        # i += 1

        while i < len(intervals):
            l, r = intervals[i]
            new_intervals.append([l, r])
            i += 1

        return new_intervals

# s = Solution()
# print(s.insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]))
