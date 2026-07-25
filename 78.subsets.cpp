// Category: algorithms
// Level: Medium
// Percent: 82.534546%

// Given an integer array nums of unique elements, return all possible subsets
// (the power set).
//
// The solution set must not contain duplicate subsets. Return the solution in
// any order.
//
//  
// Example 1:
//
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
//
//
// Example 2:
//
// Input: nums = [0]
// Output: [[],[0]]
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10
// 	-10 <= nums[i] <= 10
// 	All the numbers of nums are unique.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
  void dfs(const vector<int>& nums, int start, vector<int>& curr,
           vector<vector<int>>& res) {
    res.push_back(curr);

    for (int i = start; i < nums.size(); ++i) {
      curr.push_back(nums[i]);
      dfs(nums, i + 1, curr, res);
      curr.pop_back();
    }
  }

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> curr;
    vector<vector<int>> res;
    dfs(nums, 0, curr, res);
    return res;
  }
};
