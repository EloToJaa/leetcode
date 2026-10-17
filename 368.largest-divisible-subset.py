# Category: algorithms
# Level: Medium
# Percent: 49.862213%



# Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
# 
# 
# 	answer[i] % answer[j] == 0, or
# 	answer[j] % answer[i] == 0
# 
# 
# If there are multiple solutions, return any of them.
# 
#  
# Example 1:
# 
# Input: nums = [1,2,3]
# Output: [1,2]
# Explanation: [1,3] is also accepted.
# 
# 
# Example 2:
# 
# Input: nums = [1,2,4,8]
# Output: [1,2,4,8]
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= nums.length <= 1000
# 	1 <= nums[i] <= 2 * 10⁹
# 	All the integers in nums are unique.
# 
 

class Solution:
    def largestDivisibleSubset(self, nums: list[int]) -> list[int]:
        nums.sort()
        n = len(nums)
        size = [1] * n
        prev = [-1] * n
        best = 0
        for i in range(n):
            for j in range(i):
                if nums[i] % nums[j] != 0 or size[j] + 1 <= size[i]:
                    continue
                size[i] = size[j] + 1
                prev[i] = j
            if size[i] > size[best]:
                best = i

        answer = []
        while best != -1:
            answer.append(nums[best])
            best = prev[best]
        return answer[::-1]
