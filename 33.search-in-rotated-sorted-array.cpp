// Category: algorithms
// Level: Medium
// Percent: 45.18814%

// There is an integer array nums sorted in ascending order (with distinct
// values).
//
// Prior to being passed to your function, nums is possibly left rotated at an
// unknown index k (1 <= k < nums.length) such that the resulting array is
// [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
// (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices
// and become [4,5,6,7,0,1,2].
//
// Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
//
// You must write an algorithm with O(log n) runtime complexity.
//
//  
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:
// Input: nums = [1], target = 0
// Output: -1
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 5000
// 	-10⁴ <= nums[i] <= 10⁴
// 	All values of nums are unique.
// 	nums is an ascending array that is possibly rotated.
// 	-10⁴ <= target <= 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int searchRotation(const vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + ((r - l + 1) >> 1);
      if (nums[0] <= nums[mid])
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
  int searchTarget(const vector<int>& nums, int l, int r, int target) {
    if (r >= nums.size() || l >= nums.size()) return -1;
    int mid;
    while (l < r) {
      mid = l + ((r - l) >> 1);
      if (nums[mid] >= target)
        r = mid;
      else
        l = mid + 1;
    }
    if (nums[l] == target) return l;
    return -1;
  }

 public:
  int search(vector<int>& nums, int target) {
    int k = searchRotation(nums);
    int x = searchTarget(nums, 0, k, target);
    if (x >= 0) {
      return x;
    }
    x = searchTarget(nums, k + 1, nums.size() - 1, target);
    return x;
  }
};
