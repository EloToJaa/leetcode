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

int main() {
  vector<int> nums = {1, 3, 5};
  NumArray* obj = new NumArray(nums);
  cout << obj->sumRange(0, 2) << endl;
  obj->update(1, 2);
  cout << obj->sumRange(0, 2) << endl;
  return 0;
}
