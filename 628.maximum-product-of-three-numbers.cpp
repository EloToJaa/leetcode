// Category: algorithms
// Level: Easy
// Percent: 46.063538%

// Given an integer array nums, find three numbers whose product is maximum and
// return the maximum product.
//
//  
// Example 1:
// Input: nums = [1,2,3]
// Output: 6
// Example 2:
// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:
// Input: nums = [-1,-2,-3]
// Output: -6
//
//  
// Constraints:
//
//
// 	3 <= nums.length <= 10⁴
// 	-1000 <= nums[i] <= 1000
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int positive = 0, negative = 0;
    for (const int& num : nums) {
      if (num < 0)
        negative++;
      else if (num > 0)
        positive++;
    }
    if (negative + positive < 3) return 0;
    sort(nums.begin(), nums.end());
    int resA = 1, resB = 1;
    if (positive == 0) {
      if (negative + positive != nums.size()) return 0;
      for (int i = negative - 3; i < negative; i++) {
        resA *= nums[i];
      }
      return resA;
    }

    for (int i = 0; i < 2; i++) {
      resA *= nums[i];
    }
    resA *= nums[nums.size() - 1];
    for (int i = nums.size() - 1; i >= (int)nums.size() - 3; i--) {
      resB *= nums[i];
    }
    return max(resA, resB);
  }
};

// int main() {
//   Solution s;
//   vector<int> v = {1, 2, 3};
//   s.maximumProduct(v);
// }
