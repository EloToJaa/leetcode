// Category: algorithms
// Level: Medium
// Percent: 69.675606%

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
// in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes p and q as the lowest node in T that has both p
// and q as descendants (where we allow a node to be a descendant of itself).”
//
//  
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
//
//
// Example 2:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
// of itself according to the LCA definition.
//
//
// Example 3:
//
// Input: root = [1,2], p = 1, q = 2
// Output: 1
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree is in the range [2, 10⁵].
// 	-10⁹ <= Node.val <= 10⁹
// 	All Node.val are unique.
// 	p != q
// 	p and q will exist in the tree.
//

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
 private:
  TreeNode* ans;
  bool recurseTree(TreeNode* v, TreeNode* p, TreeNode* q) {
    if (v == nullptr) return false;
    int left = recurseTree(v->left, p, q);
    int right = recurseTree(v->right, p, q);
    int mid = (v == p || v == q);
    if (left + right + mid >= 2) {
      ans = v;
    }
    return left + right + mid > 0;
  }

 public:
  Solution() { ans = nullptr; }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    this->recurseTree(root, p, q);
    return this->ans;
  }
};
