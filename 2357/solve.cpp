#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_map<int, bool> used;
    int ans = 0;
    for (const int& num : nums) {
      if (used[num] == true || num == 0) continue;
      ans++;
      used[num] = true;
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 5, 0, 4, 5};
  cout << solution.minimumOperations(nums);
}
