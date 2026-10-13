# Category: algorithms
# Level: Medium
# Percent: 61.580883%



# Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
# 
# The solution set must not contain duplicate subsets. Return the solution in any order.
# 
#  
# Example 1:
# Input: nums = [1,2,2]
# Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
# Example 2:
# Input: nums = [0]
# Output: [[],[0]]
# 
#  
# Constraints:
# 
# 
# 	1 <= nums.length <= 10
# 	-10 <= nums[i] <= 10
# 
 

class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        res: list[list[int]] = [[]]
        used: set[tuple[int, ...]] = set()

        def backtrack(nums: list[int]):
            key = tuple(sorted(nums))
            if key in used:
                return
            
            used.add(key)
            res.append(nums)

            if len(nums) == 1:
                return
            
            for i in range(len(nums)):
                backtrack(nums[:i] + nums[i + 1:])

        backtrack(nums)
        return res
