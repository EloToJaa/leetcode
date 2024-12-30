#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    bool ascending = true;
    int n = prices.size(), sum = 0, minValue = prices[0];
    for (int i = 1; i < n; i++) {
      bool newAscending = prices[i - 1] < prices[i];
      if (!ascending && newAscending) {
        minValue = prices[i - 1];
      } else if (ascending && !newAscending) {
        sum += max(prices[i - 1] - minValue, 0);
      }

      ascending = newAscending;
    }
    if (ascending) {
      sum += max(prices[n - 1] - minValue, 0);
    }
    return sum;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {1, 2, 3, 4, 5};
  int ans = solution.maxProfit(prices);
  cout << ans;
  return 0;
}
