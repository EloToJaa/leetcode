#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pref(n), suf(n), ans(n);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++) {
      pref[i] = pref[i - 1] * nums[i];
    }
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] * nums[i];
    }

    ans[0] = suf[1];
    ans[n - 1] = pref[n - 2];
    for (int i = 1; i < n - 1; i++) {
      ans[i] = pref[i - 1] * suf[i + 1];
    }

    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4};
  auto ans = solution.productExceptSelf(nums);
  for (int num : ans) {
    cout << num << " ";
  }
  cout << "\n";
  return 0;
}
