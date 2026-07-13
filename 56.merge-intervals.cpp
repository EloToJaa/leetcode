// Category: algorithms
// Level: Medium
// Percent: 52.240433%

// Given an array of intervals where intervals[i] = [starti, endi], merge all
// overlapping intervals, and return an array of the non-overlapping intervals
// that cover all the intervals in the input.
//
//  
// Example 1:
//
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
//
// Example 2:
//
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
//
// Example 3:
//
// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.
//
//
//  
// Constraints:
//
//
// 	1 <= intervals.length <= 10⁴
// 	intervals[i].length == 2
// 	0 <= starti <= endi <= 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int maxInterval =
        (*max_element(intervals.begin(), intervals.end(),
                      [](const vector<int>& a, const vector<int>& b) {
                        return a[1] < b[1];
                      }))[1];
    vector<int> cnt(maxInterval + 1, 0);
    vector<int> same(maxInterval + 1, 0);
    for (const vector<int>& interval : intervals) {
      const int l = interval[0], r = interval[1];
      cnt[l]++;
      cnt[r]--;
      if (l == r) same[l] = true;
    }

    vector<vector<int>> result;
    if (same[0] && cnt[0] == 0) {
      vector<int> v = {0, 0};
      result.push_back(v);
    };
    int sum = cnt[0];
    int start = 0;
    for (int i = 1; i <= maxInterval; i++) {
      if (sum + cnt[i] == 0 && cnt[i] < 0) {
        vector<int> v = {start, i};
        result.push_back(v);
      } else if (sum == 0 && cnt[i] > 0) {
        start = i;
      } else if (same[i] && sum + cnt[i] == 0) {
        vector<int> v = {i, i};
        result.push_back(v);
      }
      sum += cnt[i];
    }
    return result;
  }
};
