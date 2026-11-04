# Category: algorithms
# Level: Medium
# Percent: 40.68747%



# You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
# 
# Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
# 
#  
# Example 1:
# 
# Input: nums = [1,1,4,2,3], x = 5
# Output: 2
# Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
# 
# 
# Example 2:
# 
# Input: nums = [5,6,7,8,9], x = 4
# Output: -1
# 
# 
# Example 3:
# 
# Input: nums = [3,2,20,1,1,3], x = 10
# Output: 5
# Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= nums.length <= 10⁵
# 	1 <= nums[i] <= 10⁴
# 	1 <= x <= 10⁹
# 
 

class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        target = sum(nums) - x
        max_len = -1
        curr_sum = 0

        l = 0
        for r in range(len(nums)):
            curr_sum += nums[r]

            while l <= r and curr_sum > target:
                curr_sum -= nums[l]
                l += 1
            
            if curr_sum == target:
                max_len = max(max_len, r - l + 1)
        
        if max_len == -1:
            return -1
        return len(nums) - max_len       
