// Category: algorithms
// Level: Hard
// Percent: 50.415165%

// Given an array of integers heights representing the histogram's bar height
// where the width of each bar is 1, return the area of the largest rectangle in
// the histogram.
//
//  
// Example 1:
//
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
//
//
// Example 2:
//
// Input: heights = [2,4]
// Output: 4
//
//
//  
// Constraints:
//
//
// 	1 <= heights.length <= 10⁵
// 	0 <= heights[i] <= 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    const int n = heights.size();
    stack<pair<int, int>> hStack;
    int ans = 0;
    for (int r = 0; r < n; r++) {
      int left = r;
      while (!hStack.empty() && heights[r] < hStack.top().second) {
        auto [l, height] = hStack.top();
        hStack.pop();
        ans = max(ans, (r - l) * height);
        left = l;
      }
      hStack.push({left, heights[r]});
    }
    while (!hStack.empty()) {
      auto [l, height] = hStack.top();
      hStack.pop();
      ans = max(ans, (n - l) * height);
    }
    return ans;
  }
};
