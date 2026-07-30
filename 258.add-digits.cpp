// Category: algorithms
// Level: Easy
// Percent: 69.08059%

// Given an integer num, repeatedly add all its digits until the result has only
// one digit, and return it.
//
//  
// Example 1:
//
// Input: num = 38
// Output: 2
// Explanation: The process is
// 38 --> 3 + 8 --> 11
// 11 --> 1 + 1 --> 2
// Since 2 has only one digit, return it.
//
//
// Example 2:
//
// Input: num = 0
// Output: 0
//
//
//  
// Constraints:
//
//
// 	0 <= num <= 2³¹ - 1
//
//
//  
// Follow up: Could you do it without any loop/recursion in O(1) runtime?

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int addDigits(int num) {
    if (num < 10) return num;
    int sum = 0;
    while (num > 9) {
      sum += (num % 10);
      num /= 10;
    }
    sum += num;
    return addDigits(sum);
  }
};
