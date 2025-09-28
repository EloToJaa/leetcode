// Category: algorithms
// Level: Medium
// Percent: 70.3521%

// Given an array of strings strs, group the anagrams together. You can return
// the answer in any order.
//
//  
// Example 1:
//
//
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Explanation:
//
//
// 	There is no string in strs that can be rearranged to form "bat".
// 	The strings "nat" and "tan" are anagrams as they can be rearranged to
// form each other. 	The strings "ate", "eat", and "tea" are anagrams as they
// can be rearranged to form each other.
//
//
//
// Example 2:
//
//
// Input: strs = [""]
//
// Output: [[""]]
//
//
// Example 3:
//
//
// Input: strs = ["a"]
//
// Output: [["a"]]
//
//
//  
// Constraints:
//
//
// 	1 <= strs.length <= 10⁴
// 	0 <= strs[i].length <= 100
// 	strs[i] consists of lowercase English letters.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;
    for (const string& anagram : strs) {
      string sortedAnagram = anagram;
      sort(sortedAnagram.begin(), sortedAnagram.end());

      if (map.count(sortedAnagram) == 0) {
        map[sortedAnagram] = vector<string>();
      }
      map[sortedAnagram].push_back(anagram);
    }
    for (const auto& pair : map) {
      ans.push_back(pair.second);
    }
    return ans;
  }
};
