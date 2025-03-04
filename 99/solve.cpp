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
  cout << node->val << " ";
  printTree(node->left);
  printTree(node->right);
}

class Solution {
 public:
  TreeNode *first, *second, *previous;

  void dfs(TreeNode *node) {
    if (node == NULL) return;

    dfs(node->left);

    if (first == NULL && previous->val > node->val) {
      first = previous;
    }
    if (first != NULL && previous->val > node->val) {
      second = node;
    }
    previous = node;

    dfs(node->right);
  }

  void recoverTree(TreeNode *root) {
    TreeNode start = TreeNode(INT_MIN);
    previous = &start;

    dfs(root);

    swap(first->val, second->val);
  }
};

int main() {
  Solution solution;
  TreeNode ll = TreeNode(-2147483648);
  TreeNode lr = TreeNode(2);
  TreeNode l = TreeNode(3, &ll, &lr);
  TreeNode r = TreeNode(9, NULL, NULL);
  TreeNode root = TreeNode(5, &l, &r);
  solution.recoverTree(&root);
  printTree(&root);
}
