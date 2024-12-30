#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  void reverse(vector<int>& nums, int start, int end) {
    int len = (end - start + 1) / 2;
    for (int i = 0; i < len; i++) {
      swap(nums[start + i], nums[end - i]);
    }
  }

 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n - 1);

    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
  }
};

int main() {
  Solution solution;
  vector<int> nums = {-1, -100, 3, 99};
  solution.rotate(nums, 2);
  for (int num : nums) {
    cout << num << " ";
  }
  cout << "\n";
  return 0;
}
