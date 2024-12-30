#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  int getRange(vector<int>& nums, int start, int end) {
    int maxValue = end;
    for (int i = start; i <= end; i++) {
      maxValue = max(maxValue, i + nums[i]);
    }
    return maxValue;
  }

 public:
  bool canJump(vector<int>& nums) {
    int pos = 0, range = nums[0];
    while (range < nums.size()) {
      int newRange = getRange(nums, pos + 1, range);
      if (newRange <= range) break;
      pos = range;
      range = newRange;
    }
    return range >= nums.size() - 1;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 1, 1, 4};
  bool ans = solution.canJump(nums);
  cout << ans;
  return 0;
}
