// Category: algorithms
// Level: Medium
// Percent: 57.178696%

// Given an integer array nums, return the length of the longest strictly
// increasing subsequence.
//
//  
// Example 1:
//
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
// length is 4.
//
//
// Example 2:
//
// Input: nums = [0,1,0,3,2,3]
// Output: 4
//
//
// Example 3:
//
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 2500
// 	-10⁴ <= nums[i] <= 10⁴
//
//
//  
// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
// complexity?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int findNewPosition(const vector<int>& lis, int num) {
    int l = 0, r = lis.size() - 1, mid;

    while (l < r) {
      mid = (l + r) >> 1;
      if (num < lis[mid])
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;

    vector<int> lis;
    lis.push_back(nums[0]);
    for (const int& num : nums) {
      if (num > lis[lis.size() - 1]) {
        lis.push_back(num);
        continue;
      }
      if (num == lis[lis.size() - 1]) continue;
      int pos = findNewPosition(lis, num);
      if (pos > 0 && lis[pos - 1] == num) continue;
      lis[pos] = num;
    }

    return lis.size();
  }
};

// int main() {
//   Solution solution;
//   vector<int> nums = {4, 10, 4, 3, 8, 9};
//   solution.lengthOfLIS(nums);
// }
