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

int main() {
  Solution solution;
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto anagrams = solution.groupAnagrams(strs);
  for (const vector<string>& anagramList : anagrams) {
    for (const string& anagram : anagramList) {
      cout << anagram << " ";
    }
    cout << "\n";
  }
}
