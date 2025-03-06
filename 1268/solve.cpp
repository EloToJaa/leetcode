#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products,
                                           string searchWord) {}
};

int main() {
  Solution solution;
  vector<string> products = {"mobile", "mouse", "moneypot", "monitor",
                             "mousepad"};
  vector<vector<string>> ans = solution.suggestedProducts(products, "mouse");

  for (const auto& results : ans) {
  }
}
