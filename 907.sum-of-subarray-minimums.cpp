// Category: algorithms
// Level: Medium
// Percent: 37.360683%

// Given an array of integers arr, find the sum of min(b), where b ranges over
// every (contiguous) subarray of arr. Since the answer may be large, return the
// answer modulo 10⁹ + 7.
//
//  
// Example 1:
//
// Input: arr = [3,1,2,4]
// Output: 17
// Explanation:
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
// [3,1,2,4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum is 17.
//
//
// Example 2:
//
// Input: arr = [11,81,94,43,3]
// Output: 444
//
//
//  
// Constraints:
//
//
// 	1 <= arr.length <= 3 * 10⁴
// 	1 <= arr[i] <= 3 * 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int sumSubarrayMins(vector<int>& arr) {
    stack<pair<int, int>> incStackPrev, incStackNext;
    vector<int> left(arr.size()), right(arr.size());

    for (int i = 0; i < arr.size(); i++) left[i] = i + 1;
    for (int i = 0; i < arr.size(); i++) right[i] = arr.size() - i;

    for (int i = 0; i < arr.size(); i++) {
      while (!incStackPrev.empty() && incStackPrev.top().first > arr[i])
        incStackPrev.pop();
      left[i] = incStackPrev.empty() ? i + 1 : i - incStackPrev.top().second;
      incStackPrev.push({arr[i], i});

      while (!incStackNext.empty() && incStackNext.top().first > arr[i]) {
        auto x = incStackNext.top();
        incStackNext.pop();
        right[x.second] = i - x.second;
      }
      incStackNext.push({arr[i], i});
    }

    long long ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < arr.size(); i++) {
      ans = (ans + (long long)arr[i] * left[i] * right[i]) % mod;
    }
    return (int)ans;
  }
};
