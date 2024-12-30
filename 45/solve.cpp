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
  int jump(vector<int>& nums) {
    int pos = 0, range = nums[0];
    if (nums.size() == 1) return 0;
    if (range >= nums.size() - 1) return 1;
    int ans = 1;
    while (range < nums.size()) {
      int newRange = getRange(nums, pos + 1, range);
      ans++;
      if (newRange <= range) break;
      pos = range;
      range = newRange;
    }
    if (range >= nums.size() - 1) return ans;
    return 0;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 1, 1, 4};
  int ans = solution.jump(nums);
  cout << ans;
  return 0;
}
