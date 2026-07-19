// Category: algorithms
// Level: Medium
// Percent: 47.16503%

// Given an unsorted array of integers nums, return the length of the longest
// consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.
//
//  
// Example 1:
//
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.
//
//
// Example 2:
//
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
//
// Example 3:
//
// Input: nums = [1,0,1,2]
// Output: 3
//
//
//  
// Constraints:
//
//
// 	0 <= nums.length <= 10⁵
// 	-10⁹ <= nums[i] <= 10⁹
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet;
    for (const int& num : nums) {
      numSet.insert(num);
    }
    int ans = 0;
    for (const int& num : numSet) {
      if (numSet.count(num - 1) == 0) {
        int currentNum = num;
        int currentCount = 1;
        while (numSet.count(currentNum + 1) == 1) {
          currentNum++;
          currentCount++;
        }
        ans = max(ans, currentCount);
      }
    }
    return ans;
  }
};
