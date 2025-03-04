#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int triangularSum(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> sum(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        sum[j] = (nums[j - 1] + nums[j]) % 10;
      }
      for (int j = i + 1; j < nums.size(); j++) {
        nums[j] = sum[j];
      }
    }
    return sum[sum.size() - 1];
  }
};

int main() {
  Solution solution;

  vector<int> nums = {1, 2, 3, 4, 5};
  cout << solution.triangularSum(nums) << "\n";
}
