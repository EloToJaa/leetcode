# Category: algorithms
# Level: Medium
# Percent: 69.092445%



# Given an integer array nums and an integer k, return the kth largest element in the array.
# 
# Note that it is the kth largest element in the sorted order, not the kth distinct element.
# 
# Can you solve it without sorting?
# 
#  
# Example 1:
# Input: nums = [3,2,1,5,6,4], k = 2
# Output: 5
# Example 2:
# Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
# Output: 4
# 
#  
# Constraints:
# 
# 
# 	1 <= k <= nums.length <= 10⁵
# 	-10⁴ <= nums[i] <= 10⁴
# 
 
import random


class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        pivot = random.choice(nums)
        greater = [x for x in nums if x > pivot]
        equal = [x for x in nums if x == pivot]
        if k <= len(greater):
            return self.findKthLargest(greater, k)
        if k <= len(greater) + len(equal):
            return pivot
        less = [x for x in nums if x < pivot]
        return self.findKthLargest(less, k - len(greater) - len(equal))
