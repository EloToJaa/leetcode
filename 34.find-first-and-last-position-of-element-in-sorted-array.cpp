// Category: algorithms
// Level: Medium
// Percent: 49.231228%

// Given an array of integers nums sorted in non-decreasing order, find the
// starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// You must write an algorithm with O(log n) runtime complexity.
//
//  
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
//
//  
// Constraints:
//
//
// 	0 <= nums.length <= 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
// 	nums is a non-decreasing array.
// 	-10⁹ <= target <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int findFirst(const vector<int>& nums, const int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + ((r - l) >> 1);
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    if (nums[l] != target) return -1;
    return l;
  }
  int findLast(const vector<int>& nums, const int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + ((r - l + 1) >> 1);
      if (nums[mid] <= target)
        l = mid;
      else
        r = mid - 1;
    }
    if (nums[l] != target) return -1;
    return l;
  }

 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};

    vector<int> res;
    res.push_back(findFirst(nums, target));
    res.push_back(findLast(nums, target));
    return res;
  }
};
