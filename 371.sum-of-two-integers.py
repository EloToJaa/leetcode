# Category: algorithms
# Level: Medium
# Percent: 55.77377%



# Given two integers a and b, return the sum of the two integers without using the operators + and -.
# 
#  
# Example 1:
# Input: a = 1, b = 2
# Output: 3
# Example 2:
# Input: a = 2, b = 3
# Output: 5
# 
#  
# Constraints:
# 
# 
# 	-1000 <= a, b <= 1000
# 
 

class Solution:
    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF
        a &= mask
        b &= mask
        while b:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        if a <= 0x7FFFFFFF:
            return a
        return ~(a ^ mask)
