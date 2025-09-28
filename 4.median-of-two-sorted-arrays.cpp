// Category: algorithms
// Level: Hard
// Percent: 42.95781%

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return
// the median of the two sorted arrays.
//
// The overall run time complexity should be O(log (m+n)).
//
//  
// Example 1:
//
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
//
//
// Example 2:
//
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//
//
//  
// Constraints:
//
//
// 	nums1.length == m
// 	nums2.length == n
// 	0 <= m <= 1000
// 	0 <= n <= 1000
// 	1 <= m + n <= 2000
// 	-10⁶ <= nums1[i], nums2[i] <= 10⁶
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) {
        merged.push_back(nums1[i]);
        i++;
      } else {
        merged.push_back(nums2[j]);
        j++;
      }
    }

    while (i < nums1.size()) {
      merged.push_back(nums1[i]);
      i++;
    }

    while (j < nums2.size()) {
      merged.push_back(nums2[j]);
      j++;
    }

    int n = merged.size();

    if (n % 2 == 0) {
      return (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
    } else {
      return merged[n / 2];
    }
  }
};
