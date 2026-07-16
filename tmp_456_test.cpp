#include <bits/stdc++.h>
using namespace std;

#include "456.132-pattern.cpp"

int main() {
  Solution sol;
  vector<pair<vector<int>, bool>> tests = {
      {{1, 2, 3, 4}, false},
      {{3, 1, 4, 2}, true},
      {{-1, 3, 2, 0}, true},
      {{1, 0, 1, -4, -3}, false},
      {{3, 5, 0, 3, 4}, true},
      {{1, 4, 0, -1, -2, -3, -1, -2}, true},
  };

  for (const auto& [nums, expected] : tests) {
    vector<int> input = nums;
    if (sol.find132pattern(input) != expected) {
      return 1;
    }
  }

  cout << "ok\n";
}
