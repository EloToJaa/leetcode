// Category: algorithms
// Level: Easy
// Percent: 48.34329%

// You are given an integer array nums consisting of n elements, and an integer
// k.
//
// Find a contiguous subarray whose length is equal to k that has the maximum
// average value and return this value. Any answer with a calculation error less
// than 10-5 will be accepted.
//
//  
// Example 1:
//
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
//
//
// Example 2:
//
// Input: nums = [5], k = 1
// Output: 5.00000
//
//
//  
// Constraints:
//
//
// 	n == nums.length
// 	1 <= k <= n <= 10⁵
// 	-10⁴ <= nums[i] <= 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    double res = -1e4;
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    res = max(res, (double)sum / k);
    for (int i = k; i < nums.size(); i++) {
      sum += nums[i];
      sum -= nums[i - k];
      res = max(res, (double)sum / k);
    }
    return res;
  }
};
