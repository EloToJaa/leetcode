// Category: algorithms
// Level: Medium
// Percent: 68.87185%

// You are given an integer array prices where prices[i] is the price of a given
// stock on the ith day.
//
// On each day, you may decide to buy and/or sell the stock. You can only hold
// at most one share of the stock at any time. However, you can sell and buy the
// stock multiple times on the same day, ensuring you never hold than one share
// of the stock.
//
// Find and return the maximum profit you can achieve.
//
//  
// Example 1:
//
// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
// 5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit
// = 6-3 = 3. Total profit is 4 + 3 = 7.
//
//
// Example 2:
//
// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
// 5-1 = 4. Total profit is 4.
//
//
// Example 3:
//
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the
// stock to achieve the maximum profit of 0.
//
//
//  
// Constraints:
//
//
// 	1 <= prices.length <= 3 * 10⁴
// 	0 <= prices[i] <= 10⁴
//

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
