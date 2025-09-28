// Category: algorithms
// Level: Medium
// Percent: 67.39362%

// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i].
//
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
// integer.
//
// You must write an algorithm that runs in O(n) time and without using the
// division operation.
//
//  
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
//
//  
// Constraints:
//
//
// 	2 <= nums.length <= 10⁵
// 	-30 <= nums[i] <= 30
// 	The input is generated such that answer[i] is guaranteed to fit in a
// 32-bit integer.
//
//
//  
// Follow up: Can you solve the problem in O(1) extra space complexity? (The
// output array does not count as extra space for space complexity analysis.)

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pref(n), suf(n), ans(n);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] * nums[i];
    }
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] * nums[i];
    }

    ans[0] = suf[1];
    ans[n - 1] = pref[n - 2];
    for (int i = 1; i < n - 1; i++) {
      ans[i] = pref[i - 1] * suf[i + 1];
    }

    return ans;
  }
};
