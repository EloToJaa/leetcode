// Category: algorithms
// Level: Medium
// Percent: 82.101974%

// Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.
//
//  
// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:
// Input: nums = [1]
// Output: [[1]]
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 6
// 	-10 <= nums[i] <= 10
// 	All the integers of nums are unique.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(0, nums, result);
    return result;
  }

 private:
  void backtrack(int index, vector<int>& nums, vector<vector<int>>& result) {
    if (index == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = index; i < nums.size(); ++i) {
      swap(nums[index], nums[i]);
      backtrack(index + 1, nums, result);
      swap(nums[index], nums[i]);
    }
  }
};
