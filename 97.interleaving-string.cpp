// Category: algorithms
// Level: Medium
// Percent: 41.399483%

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of
// s1 and s2.
//
// An interleaving of two strings s and t is a configuration where s and t are
// divided into n and m substrings respectively, such that:
//
//
// 	s = s₁ + s₂ + ... + sn
// 	t = t₁ + t₂ + ... + tm
// 	|n - m| <= 1
// 	The interleaving is s₁ + t₁ + s₂ + t₂ + s₃ + t₃ + ... or t₁ + s₁ + t₂ +
// s₂ + t₃ + s₃ + ...
//
//
// Note: a + b is the concatenation of strings a and b.
//
//  
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" =
// "aadbbcbcac". Since s3 can be obtained by interleaving s1 and s2, we return
// true.
//
//
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other
// string to obtain s3.
//
//
// Example 3:
//
// Input: s1 = "", s2 = "", s3 = ""
// Output: true
//
//
//  
// Constraints:
//
//
// 	0 <= s1.length, s2.length <= 100
// 	0 <= s3.length <= 200
// 	s1, s2, and s3 consist of lowercase English letters.
//
//
//  
// Follow up: Could you solve it using only O(s2.length) additional memory
// space?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) {
      return false;
    }
    vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
    for (int i = 0; i <= s1.length(); i++) {
      for (int j = 0; j <= s2.length(); j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
        } else {
          dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                     (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
      }
    }
    return dp[s1.length()][s2.length()];
  }
};
