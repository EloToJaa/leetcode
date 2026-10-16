# Category: algorithms
# Level: Medium
# Percent: 64.82986%



# Given the head of a linked list, return the list after sorting it in ascending order.
# 
#  
# Example 1:
# 
# Input: head = [4,2,1,3]
# Output: [1,2,3,4]
# 
# 
# Example 2:
# 
# Input: head = [-1,5,3,4,0]
# Output: [-1,0,3,4,5]
# 
# 
# Example 3:
# 
# Input: head = []
# Output: []
# 
# 
#  
# Constraints:
# 
# 
# 	The number of nodes in the list is in the range [0, 5 * 10⁴].
# 	-10⁵ <= Node.val <= 10⁵
# 
# 
#  
# Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
 

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode | None) -> ListNode | None:
        length = 0
        node = head
        while node:
            length += 1
            node = node.next

        dummy = ListNode(0, head)
        size = 1
        while size < length:
            tail, curr = dummy, dummy.next
            while curr:
                left = curr
                right = self.split(left, size)
                curr = self.split(right, size)
                tail = self.merge(left, right, tail)
            size *= 2
        return dummy.next

    def split(self, head: ListNode | None, size: int) -> ListNode | None:
        for _ in range(size - 1):
            if not head:
                break
            head = head.next
        if not head:
            return None
        rest = head.next
        head.next = None
        return rest

    def merge(self, a: ListNode | None, b: ListNode | None, tail: ListNode) -> ListNode:
        while a and b:
            if a.val <= b.val:
                tail.next, a = a, a.next
            else:
                tail.next, b = b, b.next
            tail = tail.next
        tail.next = a or b
        while tail.next:
            tail = tail.next
        return tail
