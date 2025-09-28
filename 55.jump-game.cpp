// Category: algorithms
// Level: Medium
// Percent: 39.11947%

// You are given an integer array nums. You are initially positioned at the
// array's first index, and each element in the array represents your maximum
// jump length at that position.
//
// Return true if you can reach the last index, or false otherwise.
//
//  
// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//
// Example 2:
//
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
// jump length is 0, which makes it impossible to reach the last index.
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁴
// 	0 <= nums[i] <= 10⁵
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int getRange(vector<int>& nums, int start, int end) {
    int maxValue = end;
    for (int i = start; i <= end; i++) {
      maxValue = max(maxValue, i + nums[i]);
    }
    return maxValue;
  }

 public:
  bool canJump(vector<int>& nums) {
    int pos = 0, range = nums[0];
    while (range < nums.size()) {
      int newRange = getRange(nums, pos + 1, range);
      if (newRange <= range) break;
      pos = range;
      range = newRange;
    }
    return range >= nums.size() - 1;
  }
};
