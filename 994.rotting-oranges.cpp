// Category: algorithms
// Level: Medium
// Percent: 58.998585%

// You are given an m x n grid where each cell can have one of three values:
//
//
// 	0 representing an empty cell,
// 	1 representing a fresh orange, or
// 	2 representing a rotten orange.
//
//
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten
// orange becomes rotten.
//
// Return the minimum number of minutes that must elapse until no cell has a
// fresh orange. If this is impossible, return -1.
//
//  
// Example 1:
//
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
//
//
// Example 2:
//
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never
// rotten, because rotting only happens 4-directionally.
//
//
// Example 3:
//
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer
// is just 0.
//
//
//  
// Constraints:
//
//
// 	m == grid.length
// 	n == grid[i].length
// 	1 <= m, n <= 10
// 	grid[i][j] is 0, 1, or 2.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int bfs(vector<vector<int>>& grid) {
    queue<tuple<int, int, int>> q;
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[row].size(); col++) {
        if (grid[row][col] == 2) q.push({row, col, 0});
      }
    }

    int ans = 0;
    while (!q.empty()) {
      auto [row, col, t] = q.front();
      q.pop();
      ans = max(ans, t);
      vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (const auto& [y, x] : dir) {
        const int py = row + y, px = col + x;
        if (py < 0 || py >= grid.size()) continue;
        if (px < 0 || px >= grid[py].size()) continue;
        if (grid[py][px] != 1) continue;
        grid[py][px] = 2;
        q.push({py, px, t + 1});
      }
    }

    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[row].size(); col++) {
        if (grid[row][col] == 1) return -1;
      }
    }
    return ans;
  }

 public:
  int orangesRotting(vector<vector<int>>& grid) { return bfs(grid); }
};
