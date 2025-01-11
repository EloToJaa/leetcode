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
