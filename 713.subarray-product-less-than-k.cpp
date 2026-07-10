// Category: algorithms
// Level: Medium
// Percent: 54.651684%

// Given an array of integers nums and an integer k, return the number of
// contiguous subarrays where the product of all the elements in the subarray is
// strictly less than k.
//
//  
// Example 1:
//
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly
// less than k.
//
//
// Example 2:
//
// Input: nums = [1,2,3], k = 0
// Output: 0
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 3 * 10⁴
// 	1 <= nums[i] <= 1000
// 	0 <= k <= 10⁶
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1) return 0;
    const int n = nums.size();
    int l = 0, prod = 1, sum = 0;
    for (int r = 0; r < n; r++) {
      prod *= nums[r];
      while (prod >= k) {
        prod /= nums[l];
        l++;
      }
      sum += r - l + 1;
    }
    return sum;
  }
};
