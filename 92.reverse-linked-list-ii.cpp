// Category: algorithms
// Level: Medium
// Percent: 51.846252%

// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.
//
//  
// Example 1:
//
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
//
//
// Example 2:
//
// Input: head = [5], left = 1, right = 1
// Output: [5]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is n.
// 	1 <= n <= 500
// 	-500 <= Node.val <= 500
// 	1 <= left <= right <= n
//
//
//  
// Follow up: Could you do it in one pass?

#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || left == right) return head;

    ListNode dummy(0, head);
    ListNode* first = &dummy;
    for (int i = 1; i < left; ++i) first = first->next;

    ListNode* prev = first;
    ListNode* curr = first->next;
    for (int i = left; i <= right; ++i) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    ListNode* tail = first->next;
    first->next = prev;
    tail->next = curr;

    return dummy.next;
  }
};
