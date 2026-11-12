# Category: algorithms
# Level: Medium
# Percent: 32.12121%



# Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2³¹, 2³¹ - 1], then return 0.
# 
# Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
# 
#  
# Example 1:
# 
# Input: x = 123
# Output: 321
# 
# 
# Example 2:
# 
# Input: x = -123
# Output: -321
# 
# 
# Example 3:
# 
# Input: x = 120
# Output: 21
# 
# 
#  
# Constraints:
# 
# 
# 	-2³¹ <= x <= 2³¹ - 1
# 
 

class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        INT_MIN = -(2**31)

        sign = -1 if x < 0 else 1
        x = abs(x)
        res = 0

        while x:
            digit = x % 10
            x = x // 10
            res = res * 10 + digit

        res *= sign
        if res < INT_MIN or res > INT_MAX:
            return 0
        return res

