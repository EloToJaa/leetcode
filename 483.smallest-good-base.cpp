// Category: algorithms
// Level: Hard
// Percent: 42.793377%

// Given an integer n represented as a string, return the smallest good base of
// n.
//
// We call k >= 2 a good base of n, if all digits of n base k are 1's.
//
//  
// Example 1:
//
// Input: n = "13"
// Output: "3"
// Explanation: 13 base 3 is 111.
//
//
// Example 2:
//
// Input: n = "4681"
// Output: "8"
// Explanation: 4681 base 8 is 11111.
//
//
// Example 3:
//
// Input: n = "1000000000000000000"
// Output: "999999999999999999"
// Explanation: 1000000000000000000 base 999999999999999999 is 11.
//
//
//  
// Constraints:
//
//
// 	n is an integer in the range [3, 10¹⁸].
// 	n does not contain any leading zeros.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 private:
  long long check(long long x, long long n) {
    long long sum = 1, cur = 1;
    for (int i = 1; i <= 62; i++) {
      cur *= x;
      sum += cur;
      if (sum == n) return 1;
      if (sum > n) return 0;
    }
    return 0;
  }

  long long searchFirst(long long l, long long r, long long n) {
    long long mid;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (check(mid, n))
        r = mid;
      else
        l = mid + 1;
    }
    return l;
  }

 public:
  string smallestGoodBase(string n) {
    long long x = stoll(n);
    return to_string(searchFirst(2, x - 1, x));
  }
};
