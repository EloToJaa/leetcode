// Category: algorithms
// Level: Medium
// Percent: 49.22%

// Given two strings s1 and s2, return true if s2 contains a permutation of s1,
// or false otherwise.
//
// In other words, return true if one of s1's permutations is the substring of
// s2.
//
//  
// Example 1:
//
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
//
//
// Example 2:
//
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
//
//
//  
// Constraints:
//
//
// 	1 <= s1.length, s2.length <= 10⁴
// 	s1 and s2 consist of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> resCharCount(26, 0);
    vector<int> permCharCount(26, 0);

    for (const char& c : s1) {
      permCharCount[c - 'a']++;
    }

    const int n = s2.size();
    int l = -1;
    for (int r = 0; r < n; r++) {
      resCharCount[s2[r] - 'a']++;
      while (r - l > s1.size()) {
        l++;
        resCharCount[s2[l] - 'a']--;
      }
      if (resCharCount == permCharCount) {
        return true;
      }
    }

    return false;
  }
};
