// Category: algorithms
// Level: Medium
// Percent: 36.340836%

// Given a string s, find the length of the longest substring without duplicate
// characters.
//
//  
// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
//
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a
// substring.
//
//
//  
// Constraints:
//
//
// 	0 <= s.length <= 5 * 10⁴
// 	s consists of English letters, digits, symbols and spaces.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLength = 0;
    unordered_set<char> charSet;
    int left = 0;

    for (int right = 0; right < n; right++) {
      if (charSet.count(s[right]) == 0) {
        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
      } else {
        while (charSet.count(s[right])) {
          charSet.erase(s[left]);
          left++;
        }
        charSet.insert(s[right]);
      }
    }

    return maxLength;
  }
};
