// Category: algorithms
// Level: Medium
// Percent: 58.199356%

// Given two strings word1 and word2, return the minimum number of operations
// required to convert word1 to word2.
//
// You have the following three operations permitted on a word:
//
//
// 	Insert a character
// 	Delete a character
// 	Replace a character
//
//
//  
// Example 1:
//
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
//
// Example 2:
//
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
//
//  
// Constraints:
//
//
// 	0 <= word1.length, word2.length <= 500
// 	word1 and word2 consist of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int word1Length = word1.size();
    int word2Length = word2.size();
    if (word1Length == 0) {
      return word2Length;
    }
    if (word2Length == 0) {
      return word1Length;
    }
    vector<vector<int>> dp(word1.length() + 1,
                           vector<int>(word2.length() + 1, 0));
    for (int i = 1; i <= word1Length; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= word2Length; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= word1Length; i++) {
      for (int j = 1; j <= word2Length; j++) {
        if (word2[j - 1] == word1[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
      }
    }

    return dp[word1Length][word2Length];
  }
};
