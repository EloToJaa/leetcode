// Category: algorithms
// Level: Hard
// Percent: 29.61358%

// As the ruler of a kingdom, you have an army of wizards at your command.
//
// You are given a 0-indexed integer array strength, where strength[i] denotes
// the strength of the ith wizard. For a contiguous group of wizards (i.e. the
// wizards' strengths form a subarray of strength), the total strength is
// defined as the product of the following two values:
//
//
// 	The strength of the weakest wizard in the group.
// 	The total of all the individual strengths of the wizards in the group.
//
//
// Return the sum of the total strengths of all contiguous groups of wizards.
// Since the answer may be very large, return it modulo 10⁹ + 7.
//
// A subarray is a contiguous non-empty sequence of elements within an array.
//
//  
// Example 1:
//
// Input: strength = [1,3,1,2]
// Output: 44
// Explanation: The following are all the contiguous groups of wizards:
// - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
// - [3] from [1,3,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
// - [1] from [1,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
// - [2] from [1,3,1,2] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
// - [1,3] from [1,3,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 *
// 4 = 4
// - [3,1] from [1,3,1,2] has a total strength of min([3,1]) * sum([3,1]) = 1 *
// 4 = 4
// - [1,2] from [1,3,1,2] has a total strength of min([1,2]) * sum([1,2]) = 1 *
// 3 = 3
// - [1,3,1] from [1,3,1,2] has a total strength of min([1,3,1]) * sum([1,3,1])
// = 1 * 5 = 5
// - [3,1,2] from [1,3,1,2] has a total strength of min([3,1,2]) * sum([3,1,2])
// = 1 * 6 = 6
// - [1,3,1,2] from [1,3,1,2] has a total strength of min([1,3,1,2]) *
// sum([1,3,1,2]) = 1 * 7 = 7 The sum of all the total strengths is 1 + 9 + 1 +
// 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.
//
//
// Example 2:
//
// Input: strength = [5,4,6]
// Output: 213
// Explanation: The following are all the contiguous groups of wizards:
// - [5] from [5,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
// - [4] from [5,4,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
// - [6] from [5,4,6] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
// - [5,4] from [5,4,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9
// = 36
// - [4,6] from [5,4,6] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10
// = 40
// - [5,4,6] from [5,4,6] has a total strength of min([5,4,6]) * sum([5,4,6]) =
// 4 * 15 = 60 The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60
// = 213.
//
//
//  
// Constraints:
//
//
// 	1 <= strength.length <= 10⁵
// 	1 <= strength[i] <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int totalStrength(vector<int>& strength) {
    const int mod = 1e9 + 7;
    const int n = strength.size();

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = (prefix[i] + strength[i]) % mod;
    }

    vector<long long> prefixPrefix(n + 2, 0);
    for (int i = 0; i <= n; ++i) {
      prefixPrefix[i + 1] = (prefixPrefix[i] + prefix[i]) % mod;
    }

    vector<int> left(n, -1), right(n, n), st;
    st.reserve(n);
    for (int i = 0; i < n; ++i) {
      while (!st.empty() && strength[st.back()] >= strength[i]) st.pop_back();
      if (!st.empty()) left[i] = st.back();
      st.push_back(i);
    }

    st.clear();
    for (int i = n - 1; i >= 0; --i) {
      while (!st.empty() && strength[st.back()] > strength[i]) st.pop_back();
      if (!st.empty()) right[i] = st.back();
      st.push_back(i);
    }

    long long answer = 0;
    for (int i = 0; i < n; ++i) {
      const int l = left[i];
      const int r = right[i];
      const long long leftCount = i - l;
      const long long rightCount = r - i;
      const long long leftSum =
          (prefixPrefix[i + 1] - prefixPrefix[l + 1] + mod) % mod;
      const long long rightSum =
          (prefixPrefix[r + 1] - prefixPrefix[i + 1] + mod) % mod;
      const long long total =
          (rightSum * leftCount - leftSum * rightCount) % mod;
      answer = (answer + strength[i] * total) % mod;
    }

    return (answer + mod) % mod;
  }
};
