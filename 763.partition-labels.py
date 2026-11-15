# Category: algorithms
# Level: Medium
# Percent: 81.958626%



# You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
# 
# Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
# 
# Return a list of integers representing the size of these parts.
# 
#  
# Example 1:
# 
# Input: s = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
# 
# 
# Example 2:
# 
# Input: s = "eccbbbbdec"
# Output: [10]
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= s.length <= 500
# 	s consists of lowercase English letters.
# 
 

class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        counter = {}
        for c in s:
            if c not in counter:
                counter[c] = 0
            counter[c] += 1

        res = []
        start = 0
        chars = set()
        for i in range(len(s)):
            c = s[i]
            if c not in chars:
                chars.add(c)
            counter[c] -= 1

            if counter[c] == 0:
                chars.remove(c)
                counter.pop(c)

            if len(chars) == 0:
                res.append(i - start + 1)
                start = i + 1

        return res
