// Category: algorithms
// Level: Easy
// Percent: 63.93442%

// Given two strings ransomNote and magazine, return true if ransomNote can be
// constructed by using the letters from magazine and false otherwise.
//
// Each letter in magazine can only be used once in ransomNote.
//
//  
// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true
//
//  
// Constraints:
//
//
// 	1 <= ransomNote.length, magazine.length <= 10⁵
// 	ransomNote and magazine consist of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int counter[256];
    for (int i = 0; i < 256; i++) counter[i] = 0;
    for (int i = 0; i < magazine.size(); i++) counter[magazine[i]]++;
    for (int i = 0; i < ransomNote.size(); i++) {
      if (counter[ransomNote[i]] == 0) return false;
      counter[ransomNote[i]]--;
    }
    return true;
  }
};
