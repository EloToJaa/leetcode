# Category: algorithms
# Level: Medium
# Percent: 58.186646%



# Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
# 
# Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
# 
#  
# Example 1:
# 
# Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
# Output: true
# Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
# 
# 
# Example 2:
# 
# Input: hand = [1,2,3,4,5], groupSize = 4
# Output: false
# Explanation: Alice's hand can not be rearranged into groups of 4.
# 
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= hand.length <= 10⁴
# 	0 <= hand[i] <= 10⁹
# 	1 <= groupSize <= hand.length
# 
# 
#  
# Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 
import heapq


class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        if len(hand) % groupSize > 0:
            return False

        counter = {}
        for h in hand:
            if h not in counter:
                counter[h] = 0
            counter[h] += 1

        heap = list(counter.keys())
        heapq.heapify(heap)

        curr_len = 0
        while curr_len < len(hand):
            start = heap[0]
            while counter[start] == 0:
                heapq.heappop(heap)
                start = heap[0]

            for i in range(groupSize):
                curr = start + i
                if curr not in counter or counter[curr] <= 0:
                    return False
                counter[curr] -= 1
                curr_len += 1

        return True
