# Category: algorithms
# Level: Medium
# Percent: 41.042336%



# Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
# 
# 
# 	0 <= a, b, c, d < n
# 	a, b, c, and d are distinct.
# 	nums[a] + nums[b] + nums[c] + nums[d] == target
# 
# 
# You may return the answer in any order.
# 
#  
# Example 1:
# 
# Input: nums = [1,0,-1,0,-2,2], target = 0
# Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
# 
# 
# Example 2:
# 
# Input: nums = [2,2,2,2,2], target = 8
# Output: [[2,2,2,2]]
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= nums.length <= 200
# 	-10⁹ <= nums[i] <= 10⁹
# 	-10⁹ <= target <= 10⁹
# 
 

class Solution:
    def twoSum(self, nums: list[int], target: int, start: int, quad: list[int], res: list[list[int]]):
        l, r = start, len(nums) - 1
        while l < r:
            if nums[l] + nums[r] < target:
                l += 1
            elif nums[l] + nums[r] > target:
                r -= 1
            else:
                res.append(quad + [nums[l], nums[r]])
                l += 1
                while l < r and nums[l] == nums[l - 1]:
                    l += 1

    def kSum(self, nums: list[int], k: int, start: int, target: int, quad: list[int], res: list[list[int]]):
        if k == 2:
            self.twoSum(nums, target, start, quad, res)
            return

        for i in range(start, len(nums) - k + 1):
            if i > start and nums[i] == nums[i - 1]:
                continue
            quad.append(nums[i])
            self.kSum(nums, k - 1, i + 1, target - nums[i], quad, res)
            quad.pop()

    def fourSum(self, nums: list[int], target: int) -> list[list[int]]:
        nums.sort()
        res = []
        self.kSum(nums, 4, 0, target, [], res)
        return res
        
