// Category: algorithms
// Level: Medium
// Percent: 49.699173%

// Given an integer array nums, return true if you can partition the array into
// two subsets such that the sum of the elements in both subsets is equal or
// false otherwise.
//
//  
// Example 1:
//
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
// Example 2:
//
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 200
// 	1 <= nums[i] <= 100
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;

    const int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (const int num : nums) {
      for (int current = target; current >= num; current--) {
        if (dp[current - num]) dp[current] = true;
      }
    }

    return dp[target];
  }
};
