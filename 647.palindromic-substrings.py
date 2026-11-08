# Category: algorithms
# Level: Medium
# Percent: 72.97932%



# Given a string s, return the number of palindromic substrings in it.
# 
# A string is a palindrome when it reads the same backward as forward.
# 
# A substring is a contiguous sequence of characters within the string.
# 
#  
# Example 1:
# 
# Input: s = "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
# 
# 
# Example 2:
# 
# Input: s = "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 1000
# 	s consists of lowercase English letters.
# 
 

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        def expand(l, r):
            res = 0
            while 0 <= l <= r < n and s[l] == s[r]:
                res += 1
                l -= 1
                r += 1
            return res
        
        res = 0
        for i in range(n):
            res += expand(i, i)
        for i in range(1, n):
            res += expand(i - 1, i)

        return res
