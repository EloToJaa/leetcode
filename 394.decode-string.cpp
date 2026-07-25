// Category: algorithms
// Level: Medium
// Percent: 62.860203%

// Given an encoded string, return its decoded string.
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the
// square brackets is being repeated exactly k times. Note that k is guaranteed
// to be a positive integer.
//
// You may assume that the input string is always valid; there are no extra
// white spaces, square brackets are well-formed, etc. Furthermore, you may
// assume that the original data does not contain any digits and that digits are
// only for those repeat numbers, k. For example, there will not be input like
// 3a or 2[4].
//
// The test cases are generated so that the length of the output will never
// exceed 10⁵.
//
//  
// Example 1:
//
// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
//
//
// Example 2:
//
// Input: s = "3[a2[c]]"
// Output: "accaccacc"
//
//
// Example 3:
//
// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 30
// 	s consists of lowercase English letters, digits, and square brackets
// '[]'. 	s is guaranteed to be a valid input. 	All the integers in s
// are in the range [1, 300].
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  bool isChar(const char& c) { return c >= 'a' && c <= 'z'; }

 public:
  string decodeString(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ']') {
        string decodedString;
        while (st.top() != '[') {
          decodedString.push_back(st.top());
          st.pop();
        }
        st.pop();

        int base = 1;
        int k = 0;
        while (!st.empty() && isdigit(st.top())) {
          k += (st.top() - '0') * base;
          st.pop();
          base *= 10;
        }

        reverse(decodedString.begin(), decodedString.end());

        while (k-- > 0) {
          for (char c : decodedString) {
            st.push(c);
          }
        }
      } else {
        st.push(s[i]);
      }
    }

    string result;
    result.reserve(st.size());
    while (!st.empty()) {
      result.push_back(st.top());
      st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
