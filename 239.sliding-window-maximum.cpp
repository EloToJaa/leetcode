// Category: algorithms
// Level: Hard
// Percent: 48.960228%

// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right. You can
// only see the k numbers in the window. Each time the sliding window moves
// right by one position.
//
// Return the max sliding window.
//
//  
// Example 1:
//
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation:
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// Example 2:
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 10⁵
// 	-10⁴ <= nums[i] <= 10⁴
// 	1 <= k <= nums.length
//

#include <bits/stdc++.h>

using namespace std;

class MonoQueue {
 private:
  int pops = 0, pushes = 0;
  deque<pair<int, int>> queue;

 public:
  void push(const int& val) {
    while (!queue.empty() and queue.back().first <= val) queue.pop_back();
    pushes++;
    queue.push_back({val, pushes});
  }

  void pop() {
    pops++;
    if (!queue.empty() and pops == queue.front().second) queue.pop_front();
  }

  int max() {
    if (queue.empty()) return numeric_limits<int>::lowest();
    return queue.front().first;
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    MonoQueue q;
    for (int i = 0; i < k; i++) {
      q.push(nums[i]);
    }
    res.push_back(q.max());
    for (int i = k; i < nums.size(); i++) {
      q.push(nums[i]);
      q.pop();
      res.push_back(q.max());
    }
    return res;
  }
};
