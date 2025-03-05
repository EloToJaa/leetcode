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

int main() {
  Solution solution;
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  vector<vector<int>> resultPoints = solution.kClosest(points, 2);
  for (const vector<int>& point : resultPoints) {
    cout << point[0] << " " << point[1] << "\n";
  }
}
