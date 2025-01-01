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

int main() {
  Solution solution;
  return 0;
}
