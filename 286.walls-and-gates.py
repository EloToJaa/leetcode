# Category: algorithms
# Level: Medium

# You are given an m x n grid rooms initialized with these three possible values:
#
# 	-1 A wall or an obstacle.
# 	0 A gate.
# 	INF Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF.
#
# Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
#
# Example 1:
# Input: rooms = [[INF,-1,0,INF],[INF,INF,INF,-1],[INF,-1,INF,-1],[0,-1,INF,INF]]
# Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
# Example 2:
# Input: rooms = [[-1]]
# Output: [[-1]]
#
# Constraints:
#
# 	m == rooms.length
# 	n == rooms[i].length
# 	1 <= m, n <= 250
# 	rooms[i][j] is -1, 0, or 2^31 - 1.

from collections import deque


class Solution:
    def wallsAndGates(self, rooms: list[list[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        R, C = len(rooms), len(rooms[0])
        gates = deque()
        visited = set()
        for r in range(R):
            for c in range(C):
                if rooms[r][c] == 0:
                    gates.append((r, c, 0))
                    visited.add((r, c))

        dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))
        while gates:
            r, c, dist = gates.popleft()
            rooms[r][c] = dist
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C):
                    continue
                if (nr, nc) in visited or rooms[nr][nc] == -1:
                    continue
                visited.add((nr, nc))
                gates.append((nr, nc, dist + 1))
