// Category: algorithms
// Level: Easy
// Percent: 50.26299%

// Given an integer n, return true if it is a power of two. Otherwise, return
// false.
//
// An integer n is a power of two, if there exists an integer x such that n ==
// 2x.
//
//  
// Example 1:
//
// Input: n = 1
// Output: true
// Explanation: 2⁰ = 1
//
//
// Example 2:
//
// Input: n = 16
// Output: true
// Explanation: 2⁴ = 16
//
//
// Example 3:
//
// Input: n = 3
// Output: false
//
//
//  
// Constraints:
//
//
// 	-2³¹ <= n <= 2³¹ - 1
//
//
//  
// Follow up: Could you solve it without loops/recursion?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    while (n > 1 && n % 2 == 0) {
      n /= 2;
    }
    return n == 1;
  }
};
