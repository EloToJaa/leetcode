# Category: algorithms
# Level: Hard
# Percent: 56.795704%



# Given an m x n integers matrix, return the length of the longest increasing path in matrix.
# 
# From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
# 
#  
# Example 1:
# 
# Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
# Output: 4
# Explanation: The longest increasing path is [1, 2, 6, 9].
# 
# 
# Example 2:
# 
# Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
# Output: 4
# Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
# 
# 
# Example 3:
# 
# Input: matrix = [[1]]
# Output: 1
# 
# 
#  
# Constraints:
# 
# 
# 	m == matrix.length
# 	n == matrix[i].length
# 	1 <= m, n <= 200
# 	0 <= matrix[i][j] <= 2³¹ - 1
# 
 

class Solution:
    def longestIncreasingPath(self, matrix: list[list[int]]) -> int:
        R, C = len(matrix), len(matrix[0])
        memo = {}

        def dfs(r, c):
            if (r, c) in memo:
                return memo[(r, c)]

            best = 1
            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C):
                    continue
                if matrix[nr][nc] <= matrix[r][c]:
                    continue
                best = max(best, dfs(nr, nc) + 1)

            memo[(r, c)] = best
            return best

        return max(dfs(r, c) for r in range(R) for c in range(C))
