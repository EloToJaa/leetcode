# Category: algorithms
# Level: Medium
# Percent: 59.45146%



# Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
# 
# Return true if it is possible. Otherwise, return false.
# 
#  
# Example 1:
# 
# Input: nums = [1,2,3,3,4,4,5,6], k = 4
# Output: true
# Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
# 
# 
# Example 2:
# 
# Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
# Output: true
# Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
# 
# 
# Example 3:
# 
# Input: nums = [1,2,3,4], k = 3
# Output: false
# Explanation: Each array should be divided in subarrays of size 3.
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= k <= nums.length <= 10⁵
# 	1 <= nums[i] <= 10⁹
# 
# 
#  
# Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
 
import heapq


class Solution:
    def isPossibleDivide(self, nums: list[int], k: int) -> bool:
        if len(nums) % k > 0:
            return False

        counter = {}
        for h in nums:
            if h not in counter:
                counter[h] = 0
            counter[h] += 1

        heap = list(counter.keys())
        heapq.heapify(heap)

        curr_len = 0
        while curr_len < len(nums):
            start = heap[0]
            while counter[start] == 0:
                heapq.heappop(heap)
                start = heap[0]

            for i in range(k):
                curr = start + i
                if curr not in counter or counter[curr] <= 0:
                    return False
                counter[curr] -= 1
                curr_len += 1

        return True
