# Category: algorithms
# Level: Easy
# Percent: 68.338005%



# Given two strings s and t, return true if t is an anagram of s, and false otherwise.
# 
#  
# Example 1:
# 
# 
# Input: s = "anagram", t = "nagaram"
# 
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "rat", t = "car"
# 
# Output: false
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length, t.length <= 5 * 10⁴
# 	s and t consist of lowercase English letters.
# 
# 
#  
# Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
 
from collections import defaultdict


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ct = defaultdict(int)
        for c in s:
            ct[c] += 1
        for c in t:
            ct[c] -= 1

        for c, cnt in ct.items():
            if cnt != 0:
                return False
        
        return True
