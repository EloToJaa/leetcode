// Category: algorithms
// Level: Medium
// Percent: 41.56175%

// Given an integer array nums, handle multiple queries of the following types:
//
//
// 	Update the value of an element in nums.
// 	Calculate the sum of the elements of nums between indices left and right
// inclusive where left <= right.
//
//
// Implement the NumArray class:
//
//
// 	NumArray(int[] nums) Initializes the object with the integer array nums.
// 	void update(int index, int val) Updates the value of nums[index] to be
// val. 	int sumRange(int left, int right) Returns the sum of the elements of
// nums between indices left and right inclusive (i.e. nums[left] + nums[left +
// 1] + ... + nums[right]).
//
//
//  
// Example 1:
//
// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]
//
// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 3 * 10⁴
// 	-100 <= nums[i] <= 100
// 	0 <= index < nums.length
// 	-100 <= val <= 100
// 	0 <= left <= right < nums.length
// 	At most 3 * 10⁴ calls will be made to update and sumRange.
//

#include <bits/stdc++.h>

using namespace std;

class NumArray {
 public:
  vector<int> tree;
  int ntree;
  int n;

  NumArray(vector<int>& nums) {
    n = nums.size(), ntree = 1;
    while (ntree < n) ntree *= 2;
    tree.resize(ntree * 2 + 1);

    for (int i = 0; i < n; i++) tree[i + ntree] = nums[i];
    for (int v = ntree - 1; v >= 1; v--)
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
  }

  void update(int index, int val) {
    index += ntree;
    tree[index] = val;
    index /= 2;
    while (index >= 1) {
      tree[index] = tree[index * 2] + tree[index * 2 + 1];
      index /= 2;
    }
  }

  int sumRange(int left, int right) {
    left += ntree, right += ntree;
    int sum = 0;
    while (left <= right) {
      if (left % 2 == 1) sum += tree[left++];
      if (right % 2 == 0) sum += tree[right--];
      left /= 2, right /= 2;
    }
    return sum;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
