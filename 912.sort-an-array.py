# Category: algorithms
# Level: Medium
# Percent: 55.925518%



# Given an array of integers nums, sort the array in ascending order and return it.
# 
# You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
# 
#  
# Example 1:
# 
# Input: nums = [5,2,3,1]
# Output: [1,2,3,5]
# Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
# 
# 
# Example 2:
# 
# Input: nums = [5,1,1,2,0,0]
# Output: [0,0,1,1,2,5]
# Explanation: Note that the values of nums are not necessarily unique.
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= nums.length <= 5 * 10⁴
# 	-5 * 10⁴ <= nums[i] <= 5 * 10⁴
# 
 
import random


class Solution:
    def partition(self, nums: list[int], l: int, r: int) -> tuple[int, int]:
        pivot = nums[random.randint(l, r)]
        lt, i, gt = l, l, r
        while i <= gt:
            if nums[i] < pivot:
                nums[lt], nums[i] = nums[i], nums[lt]
                lt += 1
                i += 1
            elif nums[i] > pivot:
                nums[i], nums[gt] = nums[gt], nums[i]
                gt -= 1
            else:
                i += 1
        return lt, gt

    def quicksort(self, nums: list[int], l: int, r: int):
        if l >= r:
            return
        lt, gt = self.partition(nums, l, r)
        self.quicksort(nums, l, lt - 1)
        self.quicksort(nums, gt + 1, r)

    def sortArray(self, nums: list[int]) -> list[int]:
        self.quicksort(nums, 0, len(nums) - 1)
        return nums
