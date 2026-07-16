// Category: algorithms
// Level: Medium
// Percent: 34.908405%

// Given an array of n integers nums, a 132 pattern is a subsequence of three
// integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] <
// nums[k] < nums[j].
//
// Return true if there is a 132 pattern in nums, otherwise, return false.
//
//  
// Example 1:
//
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.
//
//
// Example 2:
//
// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//
//
// Example 3:
//
// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1,
// 3, 0] and [-1, 2, 0].
//
//
//  
// Constraints:
//
//
// 	n == nums.length
// 	1 <= n <= 2 * 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  template <class Check>
  int search(int r, Check&& check) {
    int l = 0;
    int mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

  void add(vector<int>& bit, int index, int value) {
    for (int i = index + 1; i < bit.size(); i += i & -i) {
      bit[i] += value;
    }
  }

  int sum(const vector<int>& bit, int index) {
    int res = 0;
    for (int i = index + 1; i > 0; i -= i & -i) {
      res += bit[i];
    }
    return res;
  }

 public:
  bool find132pattern(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3) {
      return false;
    }

    vector<int> prefix_min(n);
    prefix_min[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix_min[i] = min(prefix_min[i - 1], nums[i]);
    }

    vector<int> values(nums.begin(), nums.end());
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    vector<int> bit(values.size() + 1);

    for (int i = 2; i < n; i++) {
      add(bit,
          search(values.size(),
                 [&](int mid) { return values[mid] >= nums[i]; }),
          1);
    }

    for (int j = 1; j < n - 1; j++) {
      if (prefix_min[j - 1] < nums[j]) {
        const int left = search(values.size(), [&](int mid) {
          return values[mid] > prefix_min[j - 1];
        });
        const int right =
            search(values.size(),
                   [&](int mid) { return values[mid] >= nums[j]; }) -
            1;
        if (left <= right && sum(bit, right) - sum(bit, left - 1) > 0) {
          return true;
        }
      }

      add(bit,
          search(values.size(),
                 [&](int mid) { return values[mid] >= nums[j + 1]; }),
          -1);
    }

    return false;
  }
};
