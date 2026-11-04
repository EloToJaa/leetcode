# Category: algorithms
# Level: Medium
# Percent: 59.611996%



# You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
# 
# An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
# 
# You may change 0's to 1's to connect the two islands to form one island.
# 
# Return the smallest number of 0's you must flip to connect the two islands.
# 
#  
# Example 1:
# 
# Input: grid = [[0,1],[1,0]]
# Output: 1
# 
# 
# Example 2:
# 
# Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
# Output: 2
# 
# 
# Example 3:
# 
# Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
# Output: 1
# 
# 
#  
# Constraints:
# 
# 
# 	n == grid.length == grid[i].length
# 	2 <= n <= 100
# 	grid[i][j] is either 0 or 1.
# 	There are exactly two islands in grid.
# 
 
from collections import deque


class Solution:
    def shortestBridge(self, grid: list[list[int]]) -> int:
        R, C = len(grid), len(grid[0])
        sq = deque()
        dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))

        q = deque()
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:
                    grid[r][c] = 2
                    q.append((r, c))
                    break
            if q:
                break
        
        while q:
            r, c = q.popleft()
            sq.append((r, c, 0))
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C):
                    continue
                if grid[nr][nc] != 1:
                    continue
                grid[nr][nc] = 2
                q.append((nr, nc))
        
        while sq:
            r, c, d = sq.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C):
                    continue
                if grid[nr][nc] == 2:
                    continue
                if grid[nr][nc] == 1:
                    return d
                grid[nr][nc] = 2
                sq.append((nr, nc, d + 1))

        return -1
