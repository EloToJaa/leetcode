# Category: algorithms
# Level: Medium
# Percent: 45.7388%



# You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
# 
# 
# 	Connect: A cell is connected to adjacent cells horizontally or vertically.
# 	Region: To form a region connect every 'O' cell.
# 	Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
# 
# 
# To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
# 
#  
# Example 1:
# 
# 
# Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
# 
# Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
# 
# Explanation:
# 
# In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
# 
# 
# Example 2:
# 
# 
# Input: board = [["X"]]
# 
# Output: [["X"]]
# 
# 
#  
# Constraints:
# 
# 
# 	m == board.length
# 	n == board[i].length
# 	1 <= m, n <= 200
# 	board[i][j] is 'X' or 'O'.
# 
 
from collections import deque


class Solution:
    def solve(self, board: list[list[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        R, C = len(board), len(board[0])
        visited = set()
        sq = deque()
        for r in range(R):
            if board[r][0] == 'O':
                sq.append((r, 0))
            if board[r][C - 1] == 'O':
                sq.append((r, C - 1))
        for c in range(1, C - 1):
            if board[0][c] == 'O':
                sq.append((0, c))
            if board[R - 1][c] == 'O':
                sq.append((R - 1, c))

        dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))
        while sq:
            r, c = sq.popleft()
            visited.add((r, c))
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < R and 0 <= nc < C and board[nr][nc] == 'O' and (nr, nc) not in visited:
                    sq.append((nr, nc))
                
        for r in range(R):
            for c in range(C):
                if board[r][c] == 'O' and (r, c) not in visited:
                    board[r][c] = 'X'
