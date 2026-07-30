// Category: algorithms
// Level: Medium
// Percent: 43.31148%

// Given a list of non-negative integers nums, arrange them such that they form
// the largest number and return it.
//
// Since the result may be very large, so you need to return a string instead of
// an integer.
//
//  
// Example 1:
//
// Input: nums = [10,2]
// Output: "210"
//
//
// Example 2:
//
// Input: nums = [3,30,34,5,9]
// Output: "9534330"
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 100
// 	0 <= nums[i] <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> strNums(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      strNums[i] = to_string(nums[i]);
    }
    sort(strNums.begin(), strNums.end(),
         [](const string& a, const string& b) { return a + b > b + a; });

    if (strNums[0] == "0") return "0";
    string res = "";
    for (const string& s : strNums) {
      res += s;
    }
    return res;
  }
};
