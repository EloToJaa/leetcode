// Category: algorithms
// Level: Medium
// Percent: 65.85538%

// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
//  
// Example 1:
//
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
//
//
// Example 2:
//
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
//
//
//  
// Constraints:
//
//
// 	m == grid.length
// 	n == grid[i].length
// 	1 <= m, n <= 200
// 	0 <= grid[i][j] <= 200
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[row].size(); col++) {
        if (row == 0 && col == 0) continue;
        if (row == 0)
          grid[row][col] += grid[row][col - 1];
        else if (col == 0)
          grid[row][col] += grid[row - 1][col];
        else
          grid[row][col] += min(grid[row][col - 1], grid[row - 1][col]);
      }
    }
    return grid[grid.size() - 1][grid[0].size() - 1];
  }
};
