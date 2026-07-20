// Category: algorithms
// Level: Medium
// Percent: 57.217934%

// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//  
// Example 1:
//
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//  
// Constraints:
//
//
// 	m == matrix.length
// 	n == matrix[i].length
// 	1 <= m, n <= 10
// 	-100 <= matrix[i][j] <= 100
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<vector<bool>> vis;
  vector<int> res;
  void dfs(const vector<vector<int>>& matrix, int i, int j, int x, int y) {
    const int n = matrix.size(), m = matrix[0].size();
    // cout << i << " " << j << " " << x << " " << y << "\n";
    vis[i][j] = true;
    res.push_back(matrix[i][j]);
    if (res.size() == n * m) return;
    if (i + x < 0 || i + x >= n || j + y < 0 || j + y >= m ||
        vis[i + x][j + y]) {
      if (x == 1 && y == 0) {
        dfs(matrix, i, j - 1, 0, -1);  //
      }
      if (x == -1 && y == 0) {
        dfs(matrix, i, j + 1, 0, 1);
      }
      if (x == 0 && y == 1) {
        dfs(matrix, i + 1, j + 0, 1, 0);  //
      }
      if (x == 0 && y == -1) {
        dfs(matrix, i - 1, j + 0, -1, 0);
      }
    } else {
      dfs(matrix, i + x, j + y, x, y);
    }
  }

 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    const int n = matrix.size(), m = matrix[0].size();
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    dfs(matrix, 0, 0, 0, 1);
    return res;
  }
};

// int main() {
//   Solution s;
//   vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//   s.spiralOrder(matrix);
// }
