// Category: algorithms
// Level: Medium
// Percent: 57.621235%

// Write an efficient algorithm that searches for a value target in an m x n
// integer matrix matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted in ascending from left to right.
// 	Integers in each column are sorted in ascending from top to bottom.
//
//
//  
// Example 1:
//
// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 5 Output: true
//
//
// Example 2:
//
// Input: matrix =
// [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
// target = 20 Output: false
//
//
//  
// Constraints:
//
//
// 	m == matrix.length
// 	n == matrix[i].length
// 	1 <= n, m <= 300
// 	-10⁹ <= matrix[i][j] <= 10⁹
// 	All the integers in each row are sorted in ascending order.
// 	All the integers in each column are sorted in ascending order.
// 	-10⁹ <= target <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  bool find(const vector<vector<int>>& matrix, int i, int l, int r,
            int target) {
    int mid;
    while (l < r) {
      mid = l + ((r - l) >> 1);
      if (matrix[i][mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    return matrix[i][l] == target;
  }

 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    const int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++) {
      if (find(matrix, i, 0, m - 1, target)) return true;
    }
    return false;
  }
};
