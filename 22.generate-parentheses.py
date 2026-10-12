# Category: algorithms
# Level: Medium
# Percent: 78.873215%



# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
# 
#  
# Example 1:
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
# Example 2:
# Input: n = 1
# Output: ["()"]
# 
#  
# Constraints:
# 
# 
# 	1 <= n <= 8
# 
 

class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        result = []
        path = []

        def backtrack(opened: int, closed: int) -> None:
            if len(path) == 2 * n:
                result.append("".join(path))
                return
            if opened < n:
                path.append("(")
                backtrack(opened + 1, closed)
                path.pop()
            if closed < opened:
                path.append(")")
                backtrack(opened, closed + 1)
                path.pop()

        backtrack(0, 0)
        return result
