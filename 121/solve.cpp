#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size(), ans = 0, maxValue = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      ans = max(ans, maxValue - prices[i]);
      maxValue = max(maxValue, prices[i]);
    }
    return ans;
  }
};

int main() {
  Solution solution;
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int ans = solution.maxProfit(prices);
  cout << ans;
  return 0;
}
