// Category: algorithms
// Level: Medium
// Percent: 25.59824%

// There are an infinite amount of bags on a number line, one bag for each
// coordinate. Some of these bags contain coins.
//
// You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that
// every bag from li to ri contains ci coins.
//
// The segments that coins contain are non-overlapping.
//
// You are also given an integer k.
//
// Return the maximum amount of coins you can obtain by collecting k consecutive
// bags.
//
//  
// Example 1:
//
//
// Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
//
// Output: 10
//
// Explanation:
//
// Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2
// + 0 + 4 + 4 = 10.
//
//
// Example 2:
//
//
// Input: coins = [[1,10,3]], k = 2
//
// Output: 6
//
// Explanation:
//
// Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3
// = 6.
//
//
//  
// Constraints:
//
//
// 	1 <= coins.length <= 10⁵
// 	1 <= k <= 10⁹
// 	coins[i] == [li, ri, ci]
// 	1 <= li <= ri <= 10⁹
// 	1 <= ci <= 1000
// 	The given segments are non-overlapping.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  long long maximumCoins(vector<vector<int>>& coins, int k) {
    sort(coins.begin(), coins.end());
    int n = coins.size();

    long long res = 0, cur = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
        cur += (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
        j++;
      }
      if (j < n) {
        long long part =
            (long long)max(0, coins[i][0] + k - 1 - coins[j][0] + 1) *
            coins[j][2];
        res = max(res, cur + part);
      }
      cur -= (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
    }

    cur = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      cur += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
      while (coins[j][1] < coins[i][1] - k + 1) {
        cur -= (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
        j++;
      }
      long long part =
          (long long)max(0, coins[i][1] - k - coins[j][0] + 1) * coins[j][2];
      res = max(res, cur - part);
    }

    return res;
  }
};

// int main() {
//   Solution s;
//   long long ans;
//   // vector<vector<int>> coins = {{8, 10, 1}, {1, 3, 2}, {5, 6, 4}};
//   // ans = s.maximumCoins(coins, 4);
//
//   // vector<vector<int>> coins = {{1, 10, 3}};
//   // ans = s.maximumCoins(coins, 2);
//
//   vector<vector<int>> coins = {{30, 49, 12}};
//   ans = s.maximumCoins(coins, 28);
//   cout << ans << "\n";
// }
