#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int last = 2;
    for (int i = 2; i < nums.size(); i++) {
      if (!(nums[last - 1] == nums[i] && nums[last - 2] == nums[i])) {
        if (last != i) nums[last] = nums[i];
        last++;
      }
    }

    return last;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1};
  int result = solution.removeDuplicates(nums);
  for (int i = 0; i < result; i++) {
    cout << nums[i] << " ";
  }
  cout << "\n" << result;
  return 0;
}
