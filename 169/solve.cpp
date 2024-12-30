#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int res = 0, majority = 0;
    for (int num : nums) {
      if (majority == 0) res = num;
      majority += res == num ? 1 : -1;
    }
    return res;
  }
};

int main() { return 0; }
