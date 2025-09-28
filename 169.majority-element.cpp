// Category: algorithms
// Level: Easy
// Percent: 65.49894%

// Given an array nums of size n, return the majority element.
//
// The majority element is the element that appears more than ⌊n / 2⌋ times. You
// may assume that the majority element always exists in the array.
//
//  
// Example 1:
// Input: nums = [3,2,3]
// Output: 3
// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
//
//  
// Constraints:
//
//
// 	n == nums.length
// 	1 <= n <= 5 * 10⁴
// 	-10⁹ <= nums[i] <= 10⁹
//
//
//  
// Follow-up: Could you solve the problem in linear time and in O(1) space?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int res = 0, majority = 0;
    for (int num : nums) {
      if (majority == 0) res = num;
      majority += res == num ? 1 : -1;
    }
    return res;
  }
};
