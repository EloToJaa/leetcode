// Category: algorithms
// Level: Medium
// Percent: 47.67777%

// Given an array of integers nums and an integer k, return the total number of
// subarrays whose sum equals to k.
//
// A subarray is a contiguous non-empty sequence of elements within an array.
//
//  
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 2 * 10⁴
// 	-1000 <= nums[i] <= 1000
// 	-10⁷ <= k <= 10⁷
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> pref(n + 1, 0);
    unordered_map<int, int> sumSet;
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + nums[i];
      if (sumSet.find(pref[i + 1]) != sumSet.end()) {
        sumSet[pref[i + 1]]++;
      } else {
        sumSet.insert({pref[i + 1], 1});
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      auto it = sumSet.find(k + pref[i]);
      if (it != sumSet.end() && it->second > 0) {
        // cout << i << " " << it->second << "\n";
        ans += sumSet[k + pref[i]];
      }

      sumSet[pref[i + 1]]--;
    }
    return ans;
  }
};

// int main() {
//   Solution s;
//   vector<int> nums = {1, -1, 0};
//   cout << s.subarraySum(nums, 0) << "\n";
// }
