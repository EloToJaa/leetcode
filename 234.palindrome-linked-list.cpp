// Category: algorithms
// Level: Easy
// Percent: 58.315407%

// Given the head of a singly linked list, return true if it is a palindrome or
// false otherwise.
//
//  
// Example 1:
//
// Input: head = [1,2,2,1]
// Output: true
//
//
// Example 2:
//
// Input: head = [1,2]
// Output: false
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the list is in the range [1, 10⁵].
// 	0 <= Node.val <= 9
//
//
//  
// Follow up: Could you do it in O(n) time and O(1) space?

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* secondHalf = fast == nullptr ? slow : slow->next;
    ListNode* previous = nullptr;
    while (secondHalf != nullptr) {
      ListNode* next = secondHalf->next;
      secondHalf->next = previous;
      previous = secondHalf;
      secondHalf = next;
    }

    ListNode* left = head;
    ListNode* right = previous;
    bool palindrome = true;
    while (right != nullptr) {
      if (left->val != right->val) {
        palindrome = false;
        break;
      }
      left = left->next;
      right = right->next;
    }

    secondHalf = previous;
    previous = nullptr;
    while (secondHalf != nullptr) {
      ListNode* next = secondHalf->next;
      secondHalf->next = previous;
      previous = secondHalf;
      secondHalf = next;
    }

    return palindrome;
  }
};
