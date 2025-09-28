// Category: algorithms
// Level: Easy
// Percent: 46.425724%

// Given two strings s and t, determine if they are isomorphic.
//
// Two strings s and t are isomorphic if the characters in s can be replaced to
// get t.
//
// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character, but a character may map to itself.
//
//  
// Example 1:
//
//
// Input: s = "egg", t = "add"
//
// Output: true
//
// Explanation:
//
// The strings s and t can be made identical by:
//
//
// 	Mapping 'e' to 'a'.
// 	Mapping 'g' to 'd'.
//
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
//
// Output: false
//
// Explanation:
//
// The strings s and t can not be made identical as 'o' needs to be mapped to
// both 'a' and 'r'.
//
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
//
// Output: true
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 5 * 10⁴
// 	t.length == s.length
// 	s and t consist of any valid ascii character.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char replacer[256], checker[256];
    for (int i = 0; i < 256; i++) {
      replacer[i] = 0;
      checker[i] = 0;
    }
    if (s.size() != t.size()) return false;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      char a = s[i], b = t[i];
      if (replacer[a] != 0 && replacer[a] != b) return false;
      if (checker[b] != 0 && replacer[a] != b) return false;
      replacer[a] = b;
      checker[b] = a;
    }
    return true;
  }
};
