# Category: algorithms
# Level: Hard
# Percent: 31.224178%



# Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
# 
# 
# 	'.' Matches any single character.​​​​
# 	'*' Matches zero or more of the preceding element.
# 
# 
# Return a boolean indicating whether the matching covers the entire input string (not partial).
# 
#  
# Example 1:
# 
# Input: s = "aa", p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
# 
# 
# Example 2:
# 
# Input: s = "aa", p = "a*"
# Output: true
# Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
# 
# 
# Example 3:
# 
# Input: s = "ab", p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 20
# 	1 <= p.length <= 20
# 	s contains only lowercase English letters.
# 	p contains only lowercase English letters, '.', and '*'.
# 	It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
# 
 

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo: dict[tuple[int, int], bool] = {}

        def matches(s_index: int, p_index: int) -> bool:
            state = (s_index, p_index)
            if state in memo:
                return memo[state]

            if p_index == len(p):
                return s_index == len(s)

            first_matches = (
                s_index < len(s)
                and (p[p_index] == s[s_index] or p[p_index] == ".")
            )

            if p_index + 1 < len(p) and p[p_index + 1] == "*":
                result = matches(s_index, p_index + 2) or (
                    first_matches and matches(s_index + 1, p_index)
                )
                memo[state] = result
                return result

            result = first_matches and matches(s_index + 1, p_index + 1)
            memo[state] = result
            return result

        return matches(0, 0)
