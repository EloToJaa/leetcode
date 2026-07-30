// Category: algorithms
// Level: Medium
// Percent: 48.807327%

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.
//
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.
//
//  
// Example 1:
//
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
//
//
// Example 2:
//
// Input: l1 = [0], l2 = [0]
// Output: [0]
//
//
// Example 3:
//
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in each linked list is in the range [1, 100].
// 	0 <= Node.val <= 9
// 	It is guaranteed that the list represents a number that does not have
// leading zeros.
//

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> A, B;
    for (auto current = l1; current != nullptr; current = current->next) {
      A.push_back(current->val);
    }
    for (auto current = l2; current != nullptr; current = current->next) {
      B.push_back(current->val);
    }
    ListNode* head = new ListNode();
    int move = 0;
    auto current = head;
    for (int i = 0; i < max(A.size(), B.size()); i++) {
      const int a = i >= A.size() ? 0 : A[i];
      const int b = i >= B.size() ? 0 : B[i];
      const int sum = a + b + move;
      move = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
    }
    if (move > 0) current->next = new ListNode(move);
    return head->next;
  }
};
