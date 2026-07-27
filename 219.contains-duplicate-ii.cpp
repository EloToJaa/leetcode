// Category: algorithms
// Level: Easy
// Percent: 51.531452%

// Given an integer array nums and an integer k, return true if there are two
// distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
// - j) <= k.
//
//  
// Example 1:
//
// Input: nums = [1,2,3,1], k = 3
// Output: true
//
//
// Example 2:
//
// Input: nums = [1,0,1,1], k = 1
// Output: true
//
//
// Example 3:
//
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
// 	0 <= k <= 10⁵
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < k; i++) {
      cnt[nums[i]]++;
    }
    for (int i = k; i < nums.size(); i++) {
      if (cnt[nums[i]] > 0) return true;
      cnt[nums[i]]++;
      cnt[nums[i - k]]--;
    }
    return false;
  }
};
