// Category: algorithms
// Level: Medium
// Percent: 48.76007%

// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a subarray whose sum is greater than or equal to
// target. If there is no such subarray, return 0 instead.
//
//  
// Example 1:
//
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem
// constraint.
//
//
// Example 2:
//
// Input: target = 4, nums = [1,4,4]
// Output: 1
//
//
// Example 3:
//
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
//
//
//  
// Constraints:
//
//
// 	1 <= target <= 10⁹
// 	1 <= nums.length <= 10⁵
// 	1 <= nums[i] <= 10⁴
//
//
//  
// Follow up: If you have figured out the O(n) solution, try coding another
// solution of which the time complexity is O(n log(n)).

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum < target) return 0;
    if (sum == target) return nums.size();

    int end = 0, minLen = nums.size();
    sum = 0;
    for (int start = 0; start < nums.size(); start++) {
      sum += nums[start];
      while (end < start && sum - nums[end] >= target) {
        sum -= nums[end];
        end++;
      }
      if (sum >= target) minLen = min(minLen, start - end + 1);
    }
    return minLen;
  }
};
