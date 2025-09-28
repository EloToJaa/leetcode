// Category: algorithms
// Level: Medium
// Percent: 42.47304%

// Given an integer array nums, rotate the array to the right by k steps, where
// k is non-negative.
//
//  
// Example 1:
//
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
//
// Example 2:
//
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	-2³¹ <= nums[i] <= 2³¹ - 1
// 	0 <= k <= 10⁵
//
//
//  
// Follow up:
//
//
// 	Try to come up with as many solutions as you can. There are at least
// three different ways to solve this problem. 	Could you do it in-place with
// O(1) extra space?
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  void reverse(vector<int>& nums, int start, int end) {
    int len = (end - start + 1) / 2;
    for (int i = 0; i < len; i++) {
      swap(nums[start + i], nums[end - i]);
    }
  }

 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1);

    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
  }
};
