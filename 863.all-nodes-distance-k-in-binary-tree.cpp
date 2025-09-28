// Category: algorithms
// Level: Medium
// Percent: 65.86616%

// Given the root of a binary tree, the value of a target node target, and an
// integer k, return an array of the values of all nodes that have a distance k
// from the target node.
//
// You can return the answer in any order.
//
//  
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value
// 5) have values 7, 4, and 1.
//
//
// Example 2:
//
// Input: root = [1], target = 1, k = 3
// Output: []
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree is in the range [1, 500].
// 	0 <= Node.val <= 500
// 	All the values Node.val are unique.
// 	target is the value of one of the nodes in the tree.
// 	0 <= k <= 1000
//

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<int> ans;
  vector<vector<int>> graph;
  vector<bool> vis;

  Solution() : graph(501), vis(501) {}

  void addToGraph(const int &a, const int &b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  void createNewGraph(TreeNode *node) {
    if (node == NULL) return;

    if (node->left != NULL) addToGraph(node->val, node->left->val);
    if (node->right != NULL) addToGraph(node->val, node->right->val);

    createNewGraph(node->left);
    createNewGraph(node->right);
  }

  void solveGraph(int v, int k) {
    vis[v] = true;
    if (k == 0) ans.push_back(v);
    for (const int &u : graph[v]) {
      if (vis[u]) continue;
      solveGraph(u, k - 1);
    }
  }

  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    createNewGraph(root);
    solveGraph(target->val, k);
    return ans;
  }
};
