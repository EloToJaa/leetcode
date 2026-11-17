# Category: algorithms
# Level: Medium
# Percent: 62.48434%



# Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
# 
# A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
# 
#  
# Example 1:
# 
# Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
# Output: [[5,4,11,2],[5,8,4,5]]
# Explanation: There are two paths whose sum equals targetSum:
# 5 + 4 + 11 + 2 = 22
# 5 + 8 + 4 + 5 = 22
# 
# 
# Example 2:
# 
# Input: root = [1,2,3], targetSum = 5
# Output: []
# 
# 
# Example 3:
# 
# Input: root = [1,2], targetSum = 0
# Output: []
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the tree is in the range [0, 5000].
# 	-1000 <= Node.val <= 1000
# 	-1000 <= targetSum <= 1000
# 
 

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode | None, targetSum: int) -> list[list[int]]:
        if root == None:
            return []

        res = []
        path = [root.val]

        def dfs(node, current_sum):
            if current_sum == targetSum and not node.left and not node.right:
                res.append(path.copy())
                return
            
            if node.left:
                path.append(node.left.val)
                dfs(node.left, current_sum + node.left.val)
                path.pop()
            if node.right:
                path.append(node.right.val)
                dfs(node.right, current_sum + node.right.val)
                path.pop()

        dfs(root, root.val)

        return res
