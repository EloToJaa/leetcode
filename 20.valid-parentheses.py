# Category: algorithms
# Level: Easy
# Percent: 44.454014%



# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# 
# 	Open brackets must be closed by the same type of brackets.
# 	Open brackets must be closed in the correct order.
# 	Every close bracket has a corresponding open bracket of the same type.
# 
# 
#  
# Example 1:
# 
# 
# Input: s = "()"
# 
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "()[]{}"
# 
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: s = "(]"
# 
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: s = "([])"
# 
# Output: true
# 
# 
# Example 5:
# 
# 
# Input: s = "([)]"
# 
# Output: false
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 10⁴
# 	s consists of parentheses only '()[]{}'.
# 
 

class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False

        stack = []
        par_map = {'(':')', '[':']', '{':'}'}
        for c in s:
            if c in ('(', '[', '{'):
                stack.append(c)
            elif c in (')', ']', '}'):
                if len(stack) == 0:
                    return False
                corr_par = par_map[stack[-1]]
                if c == corr_par:
                    stack.pop()
                else:
                    return False
        
        return len(stack) == 0
