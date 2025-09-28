// Category: algorithms
// Level: Hard
// Percent: 44.680237%

// Given two strings s and t of lengths m and n respectively, return the minimum
// window substring of s such that every character in t (including duplicates)
// is included in the window. If there is no such substring, return the empty
// string "".
//
// The testcases will be generated such that the answer is unique.
//
//  
// Example 1:
//
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
// from string t.
//
//
// Example 2:
//
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
//
//
// Example 3:
//
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
//
//
//  
// Constraints:
//
//
// 	m == s.length
// 	n == t.length
// 	1 <= m, n <= 10⁵
// 	s and t consist of uppercase and lowercase English letters.
//
//
//  
// Follow up: Could you find an algorithm that runs in O(m + n) time?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.length() < t.length()) {
      return "";
    }

    unordered_map<char, int> charCount;
    for (char ch : t) {
      charCount[ch]++;
    }

    int targetCharsRemaining = t.length();
    int minWindow[2] = {0, INT_MAX};
    int startIndex = 0;

    for (int endIndex = 0; endIndex < s.length(); endIndex++) {
      char ch = s[endIndex];
      if (charCount.find(ch) != charCount.end() && charCount[ch] > 0) {
        targetCharsRemaining--;
      }
      charCount[ch]--;

      if (targetCharsRemaining == 0) {
        while (true) {
          char charAtStart = s[startIndex];
          if (charCount.find(charAtStart) != charCount.end() &&
              charCount[charAtStart] == 0) {
            break;
          }
          charCount[charAtStart]++;
          startIndex++;
        }

        if (endIndex - startIndex < minWindow[1] - minWindow[0]) {
          minWindow[0] = startIndex;
          minWindow[1] = endIndex;
        }

        charCount[s[startIndex]]++;
        targetCharsRemaining++;
        startIndex++;
      }
    }

    return minWindow[1] >= s.length()
               ? ""
               : s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
  }
};
