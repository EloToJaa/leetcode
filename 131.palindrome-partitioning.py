# Category: algorithms
# Level: Medium
# Percent: 74.294075%



# Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
# 
#  
# Example 1:
# Input: s = "aab"
# Output: [["a","a","b"],["aa","b"]]
# Example 2:
# Input: s = "a"
# Output: [["a"]]
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 16
# 	s contains only lowercase English letters.
# 
 

class Solution:
    def partition(self, s: str) -> list[list[str]]:
        palindromes = set()
        
        def expand(l, r):
            while 0 <= l <= r < len(s):
                if s[l] != s[r]:
                    return

                palindromes.add(s[l:r + 1])
                l -= 1
                r += 1

        for i in range(len(s)):
            expand(i, i)
        for i in range(1, len(s)):
            expand(i - 1, i)

        res = []

        def dfs(start, partition):
            if start == len(s):
                res.append(partition[:])
                return

            for end in range(start + 1, len(s) + 1):
                piece = s[start:end]
                if piece not in palindromes:
                    continue

                partition.append(piece)
                dfs(end, partition)
                partition.pop()

        dfs(0, [])
        return res
