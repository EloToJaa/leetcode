// Category: algorithms
// Level: Easy
// Percent: 58.252056%

// Given two binary strings a and b, return their sum as a binary string.
//
//  
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
//
//  
// Constraints:
//
//
// 	1 <= a.length, b.length <= 10⁴
// 	a and b consist only of '0' or '1' characters.
// 	Each string does not contain leading zeros except for the zero itself.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int move = 0;
    const int n = max(a.size(), b.size());
    string ans;
    for (int i = 0; i < n; i++) {
      int res = move;
      int aIndex = (int)a.size() - 1 - i;
      int bIndex = (int)b.size() - 1 - i;
      if (aIndex >= 0) {
        res += (a[aIndex] - '0');
      }
      if (bIndex >= 0) {
        res += (b[bIndex] - '0');
      }
      ans.push_back((res % 2) + '0');
      move = res / 2;
    }
    if (move > 0) ans.push_back(move + '0');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
