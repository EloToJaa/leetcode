// Category: algorithms
// Level: Medium
// Percent: 36.64781%

// Given an integer array nums, find a subarray that has the largest product,
// and return the product.
//
// The test cases are generated so that the answer will fit in a 32-bit integer.
//
// Note that the product of an array with a single element is the value of that
// element.
//
//  
// Example 1:
//
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 2 * 10⁴
// 	-10 <= nums[i] <= 10
// 	The product of any subarray of nums is guaranteed to fit in a 32-bit
// integer.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int best = nums[0];
    int maxEnding = nums[0];
    int minEnding = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      const int x = nums[i];
      if (x < 0) swap(maxEnding, minEnding);

      maxEnding = max(x, maxEnding * x);
      minEnding = min(x, minEnding * x);
      best = max(best, maxEnding);
    }

    return best;
  }
};
