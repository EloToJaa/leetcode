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

int main() {
  Solution solution;
  bool ans = solution.isIsomorphic("egg", "add");
  cout << ans;
  return 0;
}
