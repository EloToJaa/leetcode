// Category: algorithms
// Level: Medium
// Percent: 57.301323%

// Given a string s, rearrange the characters of s so that any two adjacent
// characters are not the same.
//
// Return any possible rearrangement of s or return "" if not possible.
//
//  
// Example 1:
// Input: s = "aab"
// Output: "aba"
// Example 2:
// Input: s = "aaab"
// Output: ""
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 500
// 	s consists of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reorganizeString(string s) {
    const int n = s.size(), m = n / 2 + n % 2;
    vector<int> cnt(26, 0);
    for (const char& c : s) {
      cnt[c - 'a']++;
    }
    char maxLetter, nextLetter = 'a';
    int maxOccurence = 0;
    for (int i = 0; i < cnt.size(); i++) {
      if (cnt[i] > maxOccurence) {
        maxOccurence = cnt[i];
        maxLetter = i + 'a';
      }
    }

    string newString = "";
    newString.resize(n, 0);
    if (maxOccurence > m) return "";
    for (int i = 0; i < n; i += 2) {
      if (maxOccurence > 0) {
        newString[i] = maxLetter;
        cnt[maxLetter - 'a']--;
        maxOccurence--;
      } else {
        while (cnt[nextLetter - 'a'] == 0 && nextLetter < 'z') nextLetter++;
        newString[i] = nextLetter;
        cnt[nextLetter - 'a']--;
      }
    }
    for (int i = 1; i < n; i += 2) {
      while (cnt[nextLetter - 'a'] == 0 && nextLetter < 'z') nextLetter++;
      newString[i] = nextLetter;
      cnt[nextLetter - 'a']--;
    }
    return newString;
  }
};
