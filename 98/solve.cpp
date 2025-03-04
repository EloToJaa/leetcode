#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void printTree(TreeNode *node) {
  if (node == NULL) return;
  cout << node->val << ": ";
  if (node->left == NULL)
    cout << "NULL ";
  else
    cout << node->left->val << " ";
  if (node->right == NULL)
    cout << "NULL\n";
  else
    cout << node->right->val << "\n";

  printTree(node->left);
  printTree(node->right);
}

class Solution {
 public:
  bool isValidBST(TreeNode *root) { return valid(root, LONG_MIN, LONG_MAX); }

  bool valid(TreeNode *node, long mini, long maxi) {
    if (node == NULL) return true;

    if (!(mini < node->val && node->val < maxi)) return false;

    return valid(node->left, mini, node->val) &&
           valid(node->right, node->val, maxi);
  }
};

int main() {
  vector<int> nodes = {5, 1, 4, INT_MIN, INT_MIN, 3, 6};
  vector<TreeNode> tree(nodes.size());
  for (int i = 0; i < nodes.size(); i++) {
    if (nodes[i] == INT_MIN) continue;
    tree[i] = TreeNode(nodes[i]);
  }
  for (int i = 0; i < nodes.size(); i++) {
    if (i * 2 + 1 < nodes.size() && nodes[i * 2 + 1] != INT_MIN)
      tree[i].left = &tree[i * 2 + 1];
    if (i * 2 + 2 < nodes.size() && nodes[i * 2 + 2] != INT_MIN)
      tree[i].right = &tree[i * 2 + 2];
  }

  TreeNode *root = &tree[0];

  printTree(root);

  Solution solution;
  cout << solution.isValidBST(root);
}
