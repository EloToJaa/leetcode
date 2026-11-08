# Category: algorithms
# Level: Medium
# Percent: 65.65044%



# You are given the head of a singly linked-list. The list can be represented as:
# 
# L₀ → L₁ → … → Ln - 1 → Ln
# 
# 
# Reorder the list to be on the following form:
# 
# L₀ → Ln → L₁ → Ln - 1 → L₂ → Ln - 2 → …
# 
# 
# You may not modify the values in the list's nodes. Only nodes themselves may be changed.
# 
#  
# Example 1:
# 
# Input: head = [1,2,3,4]
# Output: [1,4,2,3]
# 
# 
# Example 2:
# 
# Input: head = [1,2,3,4,5]
# Output: [1,5,2,4,3]
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the list is in the range [1, 5 * 10⁴].
# 	1 <= Node.val <= 1000
# 
 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode | None) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head or not head.next:
            return

        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        second, slow.next = slow.next, None
        prev = None
        while second:
            second.next, prev, second = prev, second, second.next

        first, second = head, prev
        while second:
            first.next, first = second, first.next
            second.next, second = first, second.next
