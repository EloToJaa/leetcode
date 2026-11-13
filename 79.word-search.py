# Category: algorithms
# Level: Medium
# Percent: 47.68192%



# Given an m x n grid of characters board and a string word, return true if word exists in the grid.
# 
# The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
# 
#  
# Example 1:
# 
# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
# Output: true
# 
# 
# Example 2:
# 
# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
# Output: true
# 
# 
# Example 3:
# 
# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
# Output: false
# 
# 
#  
# Constraints:
# 
# 
# 	m == board.length
# 	n = board[i].length
# 	1 <= m, n <= 6
# 	1 <= word.length <= 15
# 	board and word consists of only lowercase and uppercase English letters.
# 
# 
#  
# Follow up: Could you use search pruning to make your solution faster with a larger board?
 

from collections import Counter


class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        visit = set()
        R, C = len(board), len(board[0])

        # Prune: the board must have enough of each letter
        board_count = Counter(ch for row in board for ch in row)
        if any(board_count[ch] < k for ch, k in Counter(word).items()):
            return False

        # Search from the rarer end
        if board_count[word[0]] > board_count[word[-1]]:
            word = word[::-1]

        def dfs(r, c, i):
            dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))

            if not (0 <= r < R and 0 <= c < C):
                return False
            if (r, c) in visit:
                return False

            char = board[r][c]
            if char != word[i]:
                return False

            visit.add((r, c))

            if i == len(word) - 1:
                return True
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if dfs(nr, nc, i + 1):
                    return True
            visit.remove((r, c))
            return False

        for r in range(R):
            for c in range(C):
                if dfs(r, c, 0):
                    return True
        
        return False
