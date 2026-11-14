# Category: algorithms
# Level: Easy

# Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
#
# Example 1:
# Input: intervals = [[0,30],[5,10],[15,20]]
# Output: false
# Example 2:
# Input: intervals = [[7,10],[2,4]]
# Output: true
#
# Constraints:
#
# 	0 <= intervals.length <= 10^4
# 	intervals[i].length == 2
# 	0 <= starti < endi <= 10^6


class Solution:
    def canAttendMeetings(self, intervals: list[list[int]]) -> bool:
        if len(intervals) == 0:
            return True
        n = max([interval[1] for interval in intervals]) + 1
        meet = [0] * n
        for l, r in intervals:
            meet[l] += 1
            meet[r] -= 1

        sum = 0
        for i in range(n):
            sum += meet[i]
            if sum > 1:
                return False
        return True
