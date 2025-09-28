// Category: algorithms
// Level: Medium
// Percent: 65.27401%

// An integer has sequential digits if and only if each digit in the number is
// one more than the previous digit.
//
// Return a sorted list of all the integers in the range [low, high] inclusive
// that have sequential digits.
//
//  
// Example 1:
// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:
// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]
//
//  
// Constraints:
//
//
// 	10 <= low <= high <= 10^9
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> numbers;
    for (int i = 1; i <= 8; i++) {
      int n = i, number = i;
      for (int j = 2; j <= 10 - i; j++) {
        n++;
        number = number * 10 + n;
        numbers.push_back(number);
      }
    }

    vector<int> sortedNumbers;
    for (const int& number : numbers) {
      if (low <= number && number <= high) sortedNumbers.push_back(number);
    }
    sort(sortedNumbers.begin(), sortedNumbers.end());

    return sortedNumbers;
  }
};
