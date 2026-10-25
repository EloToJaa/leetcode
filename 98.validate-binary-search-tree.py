# Category: algorithms
# Level: Medium
# Percent: 35.98364%



# Given the root of a binary tree, determine if it is a valid binary search tree (BST).
# 
# A valid BST is defined as follows:
# 
# 
# 	The left subtree of a node contains only nodes with keys strictly less than the node's key.
# 	The right subtree of a node contains only nodes with keys strictly greater than the node's key.
# 	Both the left and right subtrees must also be binary search trees.
# 
# 
#  
# Example 1:
# 
# Input: root = [2,1,3]
# Output: true
# 
# 
# Example 2:
# 
# Input: root = [5,1,4,null,null,3,6]
# Output: false
# Explanation: The root node's value is 5 but its right child's value is 4.
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the tree is in the range [1, 10⁴].
# 	-2³¹ <= Node.val <= 2³¹ - 1
# 
 

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isValidBST(self, root: TreeNode | None) -> bool:
        def dfs(node) -> tuple[bool, float, float]:
            if not node:
                return True, float("inf"), float("-inf")

            l_ok, l_min, l_max = dfs(node.left)
            if not l_ok:
                return False, 0, 0
            r_ok, r_min, r_max = dfs(node.right)
            if not r_ok:
                return False, 0, 0

            if not (l_max < node.val < r_min):
                return False, 0, 0

            return True, min(l_min, node.val), max(r_max, node.val)

        return dfs(root)[0]
