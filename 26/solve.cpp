#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int last = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] != nums[i]) {
        if (last != i) nums[last] = nums[i];
        last++;
      }
    }

    return last;
  }
};

int main() { return 0; }
