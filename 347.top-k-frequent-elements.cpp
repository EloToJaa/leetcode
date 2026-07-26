// Category: algorithms
// Level: Medium
// Percent: 66.82018%

// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.
//
//  
// Example 1:
//
//
// Input: nums = [1,1,1,2,2,3], k = 2
//
// Output: [1,2]
//
//
// Example 2:
//
//
// Input: nums = [1], k = 1
//
// Output: [1]
//
//
// Example 3:
//
//
// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
//
// Output: [1,2]
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	-10⁴ <= nums[i] <= 10⁴
// 	k is in the range [1, the number of unique elements in the array].
// 	It is guaranteed that the answer is unique.
//
//
//  
// Follow up: Your algorithm's time complexity must be better than O(n log n),
// where n is the array's size.

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    if (k == nums.size()) {
      return nums;
    }

    unordered_map<int, int> countMap;
    for (int n : nums) {
      countMap[n] += 1;
    }

    auto comp = [&countMap](int n1, int n2) {
      return countMap[n1] > countMap[n2];
    };
    priority_queue<int, vector<int>, decltype(comp)> heap(comp);

    for (auto [key, value] : countMap) {
      heap.push(key);
      if (heap.size() > k) heap.pop();
    }

    vector<int> top(k);
    for (int i = k - 1; i >= 0; i--) {
      top[i] = heap.top();
      heap.pop();
    }
    return top;
  }
};
