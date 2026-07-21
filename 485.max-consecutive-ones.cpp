// Category: algorithms
// Level: Easy
// Percent: 65.57443%

// Given a binary array nums, return the maximum number of consecutive 1's in
// the array.
//
//  
// Example 1:
//
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive
// 1s. The maximum number of consecutive 1s is 3.
//
//
// Example 2:
//
// Input: nums = [1,0,1,1,0,1]
// Output: 2
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	nums[i] is either 0 or 1.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0, res = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 1)
        res++;
      else {
        ans = max(ans, res);
        res = 0;
      }
    }
    ans = max(ans, res);
    return ans;
  }
};
