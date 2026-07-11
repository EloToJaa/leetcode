// Category: algorithms
// Level: Medium
// Percent: 69.9804%

// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors in
// the order red, white, and blue.
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and
// blue, respectively.
//
// You must solve this problem without using the library's sort function.
//
//  
// Example 1:
//
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
//
// Example 2:
//
// Input: nums = [2,0,1]
// Output: [0,1,2]
//
//
//  
// Constraints:
//
//
// 	n == nums.length
// 	1 <= n <= 300
// 	nums[i] is either 0, 1, or 2.
//
//
//  
// Follow up: Could you come up with a one-pass algorithm using only constant
// extra space?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    size_t next_zero = 0;
    size_t current = 0;
    size_t next_two = nums.size();

    while (current < next_two) {
      if (nums[current] == 0) {
        swap(nums[next_zero++], nums[current++]);
        continue;
      }

      if (nums[current] == 2) {
        swap(nums[current], nums[--next_two]);
        continue;
      }

      ++current;
    }
  }
};
