// Category: algorithms
// Level: Medium
// Percent: 39.399715%

// Given an integer array nums, return all the triplets [nums[i], nums[j],
// nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
// nums[k] == 0.
//
// Notice that the solution set must not contain duplicate triplets.
//
//  
// Example 1:
//
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation:
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not
// matter.
//
//
// Example 2:
//
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
//
//
// Example 3:
//
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
//
//
//  
// Constraints:
//
//
// 	3 <= nums.length <= 3000
// 	-10⁵ <= nums[i] <= 10⁵
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  void twoSum(const vector<int>& nums, int i, vector<vector<int>>& res) {
    int l = i + 1, r = nums.size() - 1, sum;
    while (l < r) {
      sum = nums[i] + nums[l] + nums[r];
      if (sum < 0) {
        l++;
      } else if (sum > 0) {
        r--;
      } else {
        res.push_back({nums[i], nums[l], nums[r]});
        l++;
        r--;
        while (l < r && nums[l] == nums[l - 1]) l++;
      }
    }
  }

 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n && nums[i] <= 0; i++) {
      if (i == 0 || nums[i - 1] != nums[i]) {
        twoSum(nums, i, res);
      }
    }
    return res;
  }
};
