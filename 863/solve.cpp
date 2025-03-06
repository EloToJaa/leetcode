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

void makeTree(const vector<int> &nodes, vector<TreeNode *> &tree) {
  tree.resize(nodes.size(), nullptr);

  for (size_t i = 0; i < nodes.size(); i++) {
    if (nodes[i] == INT_MIN) continue;
    tree[i] = new TreeNode(nodes[i]);  // Allocate TreeNode on the heap
  }

  for (size_t i = 0; i < nodes.size(); i++) {
    if (tree[i] == nullptr) continue;  // Skip if node is INT_MIN

    if (i * 2 + 1 < nodes.size() && nodes[i * 2 + 1] != INT_MIN) {
      if (tree[i * 2 + 1] != nullptr) {
        tree[i]->left = tree[i * 2 + 1];
      }
    }
    if (i * 2 + 2 < nodes.size() && nodes[i * 2 + 2] != INT_MIN) {
      if (tree[i * 2 + 2] != nullptr) {
        tree[i]->right = tree[i * 2 + 2];
      }
    }
  }
}

void freeTree(vector<TreeNode *> &tree) {
  for (TreeNode *node : tree) {
    delete node;
  }
}

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

int main() {
  vector<int> nodes = {0, 2, 1, INT_MIN, INT_MIN, 3};
  vector<TreeNode *> tree(nodes.size());
  makeTree(nodes, tree);

  TreeNode *root = tree[0];
  TreeNode *target = tree[5];

  Solution solution;
  vector<int> ans = solution.distanceK(root, target, 3);

  for (int v = 0; v <= 10; v++) {
    cout << v << ": ";
    for (const int &u : solution.graph[v]) {
      cout << u << " ";
    }
    cout << "\n";
  }

  for (const int &val : ans) {
    cout << val << " ";
  }

  freeTree(tree);
}
