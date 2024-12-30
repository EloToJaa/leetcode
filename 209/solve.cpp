#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum < target) return 0;
    if (sum == target) return nums.size();

    int end = 0, minLen = nums.size();
    sum = 0;
    for (int start = 0; start < nums.size(); start++) {
      sum += nums[start];
      while (end < start && sum - nums[end] >= target) {
        sum -= nums[end];
        end++;
      }
      if (sum >= target) minLen = min(minLen, start - end + 1);
    }
    return minLen;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int ans = solution.minSubArrayLen(7, nums);
  cout << ans;
  return 0;
}
