// Category: algorithms
// Level: Medium
// Percent: 66.37416%

// Given a string containing digits from 2-9 inclusive, return all possible
// letter combinations that the number could represent. Return the answer in any
// order.
//
// A mapping of digits to letters (just like on the telephone buttons) is given
// below. Note that 1 does not map to any letters.
//
//  
// Example 1:
//
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
//
// Example 2:
//
// Input: digits = "2"
// Output: ["a","b","c"]
//
//
//  
// Constraints:
//
//
// 	1 <= digits.length <= 4
// 	digits[i] is a digit in the range ['2', '9'].
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  vector<char> getChars(int digit) {
    switch (digit) {
      case 2:
        return {'a', 'b', 'c'};
      case 3:
        return {'d', 'e', 'f'};
      case 4:
        return {'g', 'h', 'i'};
      case 5:
        return {'j', 'k', 'l'};
      case 6:
        return {'m', 'n', 'o'};
      case 7:
        return {'p', 'q', 'r', 's'};
      case 8:
        return {'t', 'u', 'v'};
      case 9:
        return {'w', 'x', 'y', 'z'};
      default:
        return {};
    }
  }

  void dfs(vector<string>& res, string curr, string digits, int n) {
    if (n > digits.size()) return;
    if (n == digits.size()) res.push_back(curr);
    vector<char> chars = getChars(digits[n] - '0');
    for (const char& c : chars) {
      curr.push_back(c);
      dfs(res, curr, digits, n + 1);
      curr.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    dfs(res, "", digits, 0);
    return res;
  }
};
