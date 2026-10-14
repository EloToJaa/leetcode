# Category: algorithms
# Level: Medium
# Percent: 63.882915%



# Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
# 
#  
# Example 1:
# 
# Input: n = 3
# Output: 5
# 
# 
# Example 2:
# 
# Input: n = 1
# Output: 1
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= n <= 19
# 
 

class Solution:
    def numTrees(self, n: int) -> int:
        dp = [1] * (n + 1)
        for nodes in range(2, n + 1):
            dp[nodes] = sum(dp[root - 1] * dp[nodes - root] for root in range(1, nodes + 1))
        return dp[n]
