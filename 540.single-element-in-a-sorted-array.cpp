// Category: algorithms
// Level: Medium
// Percent: 59.322865%

// You are given a sorted array consisting of only integers where every element
// appears exactly twice, except for one element which appears exactly once.
//
// Return the single element that appears only once.
//
// Your solution must run in O(log n) time and O(1) space.
//
//  
// Example 1:
// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	0 <= nums[i] <= 10⁵
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + ((r - l) >> 1);
      bool shouldBeLast = mid % 2 == 1;
      if (mid == 0 && nums[0] != nums[1]) return nums[0];
      if (shouldBeLast && nums[mid - 1] != nums[mid])
        r = mid;
      else if (shouldBeLast && nums[mid - 1] == nums[mid])
        l = mid + 1;
      else if (!shouldBeLast && nums[mid - 1] == nums[mid])
        r = mid;
      else if (!shouldBeLast && nums[mid - 1] != nums[mid])
        l = mid + 1;
    }
    if (l % 2 == 0) return nums[l];
    return nums[l - 1];
  }
};
