// Category: algorithms
// Level: Hard
// Percent: 56.749325%



// Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
// 
// Return the minimum total distance between each house and its nearest mailbox.
// 
// The test cases are generated so that the answer fits in a 32-bit integer.
// 
//  
// Example 1:
// 
// Input: houses = [1,4,8,10,20], k = 3
// Output: 5
// Explanation: Allocate mailboxes in position 3, 9 and 20.
// Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
// 
// 
// Example 2:
// 
// Input: houses = [2,3,5,12,18], k = 2
// Output: 9
// Explanation: Allocate mailboxes in position 3 and 14.
// Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
// 
// 
//  
// Constraints:
// 
// 
// 	1 <= k <= houses.length <= 100
// 	1 <= houses[i] <= 10⁴
// 	All the integers of houses are unique.
// 
 

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(), houses.end());
    const int n = houses.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));
    for (int left = n - 1; left >= 0; left--) {
      for (int right = left + 1; right < n; right++) {
        cost[left][right] =
            cost[left + 1][right - 1] + houses[right] - houses[left];
      }
    }

    constexpr int kInf = numeric_limits<int>::max() / 4;
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, kInf));
    dp[0][0] = 0;
    for (int used = 1; used <= k; used++) {
      for (int covered = 1; covered <= n; covered++) {
        for (int prev = 0; prev < covered; prev++) {
          dp[used][covered] =
              min(dp[used][covered], dp[used - 1][prev] + cost[prev][covered - 1]);
        }
      }
    }

    return dp[k][n];
  }
};

