// Category: algorithms
// Level: Medium
// Percent: 60.059982%

// You are given a string s and an integer k. You can choose any character of
// the string and change it to any other uppercase English character. You can
// perform this operation at most k times.
//
// Return the length of the longest substring containing the same letter you can
// get after performing the above operations.
//
//  
// Example 1:
//
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.
//
//
// Example 2:
//
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// There may exists other ways to achieve this answer too.
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 10⁵
// 	s consists of only uppercase English letters.
// 	0 <= k <= s.length
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int charCount[26] = {};
    int l = 0;
    int maxFreq = 0;
    int result = 0;

    for (int r = 0; r < static_cast<int>(s.size()); r++) {
      const int c = s[r] - 'A';
      charCount[c]++;
      maxFreq = max(maxFreq, charCount[c]);

      if (r - l + 1 - maxFreq > k) {
        charCount[s[l] - 'A']--;
        l++;
      }

      result = max(result, r - l + 1);
    }

    return result;
  }
};
