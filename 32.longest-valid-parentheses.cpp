// Category: algorithms
// Level: Hard
// Percent: 35.706844%

// Given a string containing just the characters '(' and ')', return the length
// of the longest valid (well-formed) parentheses substring.
//
//  
// Example 1:
//
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
//
//
// Example 2:
//
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
//
//
// Example 3:
//
// Input: s = ""
// Output: 0
//
//
//  
// Constraints:
//
//
// 	0 <= s.length <= 3 * 10⁴
// 	s[i] is '(', or ')'.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty()) {
          st.push(i);
        } else {
          maxLen = max(maxLen, i - st.top());
        }
      }
    }
    return maxLen;
  }
};
