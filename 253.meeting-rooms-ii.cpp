// Category: algorithms
// Level: Medium
// Percent: 52.7359%

// Given an array of meeting time intervals intervals where intervals[i] =
// [starti, endi], return the minimum number of conference rooms required.
//
//  
// Example 1:
// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2
// Example 2:
// Input: intervals = [[7,10],[2,4]]
// Output: 1
//
//  
// Constraints:
//
//
// 	1 <= intervals.length <= 10⁴
// 	0 <= starti < endi <= 10⁶
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    priority_queue<int> pq;
    int res = 0;
    for (const vector<int>& interval : intervals) {
      int l = interval[0], r = interval[1];
      pq.push(-r);
      while (-pq.top() <= l) pq.pop();
      res = max(res, (int)pq.size());
    }
    return res;
  }
};
