#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(
        boxTypes.begin(), boxTypes.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] > b[1]; });

    int ans = 0;
    for (const vector<int>& data : boxTypes) {
      if (truckSize == 0) return ans;

      int boxes = min(data[0], truckSize);
      ans += boxes * data[1];

      truckSize -= boxes;
    }
    return ans;
  }
};

int main() {}
