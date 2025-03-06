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

int main() {
  Solution solution;
  vector<int> ans = solution.sequentialDigits(100, 300);
  for (const int& val : ans) {
    cout << val << " ";
  }
  cout << "\n";
}
