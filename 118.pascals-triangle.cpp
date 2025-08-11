// Category: algorithms
// Level: Easy
// Percent: 76.43968%

// Given an integer numRows, return the first numRows of Pascal's triangle.
//
// In Pascal's triangle, each number is the sum of the two numbers directly
// above it as shown:
//
//  
// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:
// Input: numRows = 1
// Output: [[1]]
//
//  
// Constraints:
//
//
// 	1 <= numRows <= 30
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle = {{1}};
    for (int row = 2; row <= numRows; row++) {
      auto prevRow = triangle[row - 2];
      vector<int> newRow = {1};
      for (int num = 2; num < row; num++) {
        newRow.push_back(prevRow[num - 2] + prevRow[num - 1]);
      }
      newRow.push_back(1);
      triangle.push_back(newRow);
    }
    return triangle;
  }
};

int main() {
  Solution solution;
  auto triangle = solution.generate(4);
  for (int i = 0; i < triangle.size(); i++) {
    for (int j = 0; j < triangle[i].size(); j++) {
      cout << triangle[i][j] << " ";
    }
    cout << "\n";
  }
}
