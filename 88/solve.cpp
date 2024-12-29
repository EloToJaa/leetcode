#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int mergedLen = m + n;
    int a = m - 1, b = n - 1;
    for (int i = mergedLen - 1; i >= 0; i--) {
      if (a < 0) {
        nums1[i] = nums2[b];
        b--;
        continue;
      }
      if (b < 0) {
        nums1[i] = nums1[a];
        a--;
        continue;
      }
      if (nums1[a] > nums2[b]) {
        nums1[i] = nums1[a];
        a--;
      } else {
        nums1[i] = nums2[b];
        b--;
      }
    }
  }
};

int main() {
  Solution solution;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};
  solution.merge(nums1, 3, nums2, nums2.size());

  for (auto value : nums1) {
    cout << value << " ";
  }
  cout << "\n";

  return 0;
}
