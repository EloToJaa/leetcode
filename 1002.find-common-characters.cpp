// Category: algorithms
// Level: Easy
// Percent: 74.75157%

// Given a string array words, return an array of all characters that show up in
// all strings within the words (including duplicates). You may return the
// answer in any order.
//
//  
// Example 1:
// Input: words = ["bella","label","roller"]
// Output: ["e","l","l"]
// Example 2:
// Input: words = ["cool","lock","cook"]
// Output: ["c","o"]
//
//  
// Constraints:
//
//
// 	1 <= words.length <= 100
// 	1 <= words[i].length <= 100
// 	words[i] consists of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    vector<int> a(26, 0), b(26, 0);
    vector<string> res;
    for (const char& c : words[0]) {
      b[c - 'a']++;
    }
    for (int i = 1; i < words.size(); i++) {
      for (int i = 0; i < 26; i++) a[i] = 0;
      for (const char& c : words[i]) {
        a[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        b[i] = min(a[i], b[i]);
      }
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < b[i]; j++) {
        char c = i + 'a';
        res.push_back(string(1, c));
      }
    }
    return res;
  }
};
