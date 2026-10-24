# Category: algorithms
# Level: Medium
# Percent: 38.155865%



# Given a string s, return the longest palindromic substring in s.
# 
#  
# Example 1:
# 
# Input: s = "babad"
# Output: "bab"
# Explanation: "aba" is also a valid answer.
# 
# 
# Example 2:
# 
# Input: s = "cbbd"
# Output: "bb"
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 1000
# 	s consist of only digits and English letters.
# 
 

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = (0, 0)
        for i in range(len(s)):
            l, r = i, i
            while l >= 0 and r < len(s):
                if s[l] != s[r]:
                    break
                if r - l + 1 > ans[1] - ans[0] + 1:
                    ans = (l, r)
                l -= 1
                r += 1

        for i in range(len(s) - 1):
            l, r = i, i + 1
            while l >= 0 and r < len(s):
                if s[l] != s[r]:
                    break
                if r - l + 1 > ans[1] - ans[0] + 1:
                    ans = (l, r)
                l -= 1
                r += 1

        return s[ans[0]:ans[1] + 1]
