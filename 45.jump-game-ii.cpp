// Category: algorithms
// Level: Medium
// Percent: 41.144703%

// You are given a 0-indexed array of integers nums of length n. You are
// initially positioned at index 0.
//
// Each element nums[i] represents the maximum length of a forward jump from
// index i. In other words, if you are at index i, you can jump to any index (i
// + j) where:
//
//
// 	0 <= j <= nums[i] and
// 	i + j < n
//
//
// Return the minimum number of jumps to reach index n - 1. The test cases are
// generated such that you can reach index n - 1.
//
//  
// Example 1:
//
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1
// step from index 0 to 1, then 3 steps to the last index.
//
//
// Example 2:
//
// Input: nums = [2,3,0,1,4]
// Output: 2
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁴
// 	0 <= nums[i] <= 1000
// 	It's guaranteed that you can reach nums[n - 1].
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
  int jump(vector<int>& nums) {
    int pos = 0, range = nums[0];
    if (nums.size() == 1) return 0;
    if (range >= nums.size() - 1) return 1;
    int ans = 1;
    while (range < nums.size()) {
      int newRange = getRange(nums, pos + 1, range);
      ans++;
      if (newRange <= range) break;
      pos = range;
      range = newRange;
    }
    if (range >= nums.size() - 1) return ans;
    return 0;
  }
};
