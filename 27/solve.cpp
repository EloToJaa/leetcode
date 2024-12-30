#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int last = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        if (last != i) nums[last] = nums[i];
        last++;
      }
    }

    return last;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {3, 2, 2, 3};
  int result = solution.removeElement(nums, 3);
  for (auto val : nums) {
    cout << val << " ";
  }
  cout << "\n" << result;
  return 0;
}
