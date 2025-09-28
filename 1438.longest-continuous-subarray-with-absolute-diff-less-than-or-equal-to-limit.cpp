// Category: algorithms
// Level: Medium
// Percent: 56.69833%

// Given an array of integers nums and an integer limit, return the size of the
// longest non-empty subarray such that the absolute difference between any two
// elements of this subarray is less than or equal to limit.
//
//  
// Example 1:
//
// Input: nums = [8,2,4,7], limit = 4
// Output: 2
// Explanation: All subarrays are:
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.
//
//
// Example 2:
//
// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute
// diff is |2-7| = 5 <= 5.
//
//
// Example 3:
//
// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	1 <= nums[i] <= 10⁹
// 	0 <= limit <= 10⁹
//

#include <bits/stdc++.h>

#include <deque>

using namespace std;

class Solution {
 public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> minQueue, maxQueue;
    int r, l = 0, ans = 0;
    for (r = 0; r < nums.size(); r++) {
      while (!minQueue.empty() && minQueue.back() > nums[r])
        minQueue.pop_back();
      while (!maxQueue.empty() && maxQueue.back() < nums[r])
        maxQueue.pop_back();

      minQueue.push_back(nums[r]);
      maxQueue.push_back(nums[r]);
      if (maxQueue.front() - minQueue.front() > limit) {
        if (maxQueue.front() == nums[l]) maxQueue.pop_front();
        if (minQueue.front() == nums[l]) minQueue.pop_front();
        l++;
      }
    }
    return r - l;
  }
};
