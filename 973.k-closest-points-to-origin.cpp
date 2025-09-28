// Category: algorithms
// Level: Medium
// Percent: 67.562065%

// Given an array of points where points[i] = [xi, yi] represents a point on the
// X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//
// The distance between two points on the X-Y plane is the Euclidean distance
// (i.e., √(x₁ - x₂)² + (y₁ - y₂)²).
//
// You may return the answer in any order. The answer is guaranteed to be unique
// (except for the order that it is in).
//
//  
// Example 1:
//
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just
// [[-2,2]].
//
//
// Example 2:
//
// Input: points = [[3,3],[5,-1],[-2,4]], k = 2
// Output: [[3,3],[-2,4]]
// Explanation: The answer [[-2,4],[3,3]] would also be accepted.
//
//
//  
// Constraints:
//
//
// 	1 <= k <= points.length <= 10⁴
// 	-10⁴ <= xi, yi <= 10⁴
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int getDistance(const vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(),
         [&](const vector<int>& a, const vector<int>& b) {
           return getDistance(a) < getDistance(b);
         });
    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
};
