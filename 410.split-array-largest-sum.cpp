// Category: algorithms
// Level: Hard
// Percent: 60.935455%

// Given an integer array nums and an integer k, split nums into k non-empty
// subarrays such that the largest sum of any subarray is minimized.
//
// Return the minimized largest sum of the split.
//
// A subarray is a contiguous part of the array.
//
//  
// Example 1:
//
// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum
// among the two subarrays is only 18.
//
//
// Example 2:
//
// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum
// among the two subarrays is only 9.
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 1000
// 	0 <= nums[i] <= 10⁶
// 	1 <= k <= min(50, nums.length)
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  bool check(const vector<int>& nums, int largest, int k) {
    int sum = 0, groups = 1;
    for (int num : nums) {
      if (num > largest) return false;
      if (sum + num <= largest) {
        sum += num;
        continue;
      }
      groups++;
      if (groups > k) return false;
      sum = num;
    }
    return true;
  }

  int find(const vector<int>& nums, int l, int r, int k) {
    int mid;
    while (l < r) {
      mid = l + ((r - l) >> 1);
      if (check(nums, mid, k))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

 public:
  int splitArray(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return find(nums, 0, sum, k);
  }
};
