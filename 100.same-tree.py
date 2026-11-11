# Category: algorithms
# Level: Easy
# Percent: 67.47008%



# Given the roots of two binary trees p and q, write a function to check if they are the same or not.
# 
# Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
# 
#  
# Example 1:
# 
# Input: p = [1,2,3], q = [1,2,3]
# Output: true
# 
# 
# Example 2:
# 
# Input: p = [1,2], q = [1,null,2]
# Output: false
# 
# 
# Example 3:
# 
# Input: p = [1,2,1], q = [1,1,2]
# Output: false
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in both trees is in the range [0, 100].
# 	-10⁴ <= Node.val <= 10⁴
# 
 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode | None, q: TreeNode | None) -> bool:
        def dfs(a, b):
            if not a and not b:
                return True
            if not a or not b:
                return False
            if a.val != b.val:
                return False
            
            l = dfs(a.left, b.left)
            r = dfs(a.right, b.right)

            return l and r
        
        return dfs(p, q)
