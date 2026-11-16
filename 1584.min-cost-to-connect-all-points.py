# Category: algorithms
# Level: Medium
# Percent: 72.04313%



# You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
# 
# The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
# 
# Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
# 
#  
# Example 1:
# 
# Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
# Output: 20
# Explanation: 
# 
# We can connect the points as shown above to get the minimum cost of 20.
# Notice that there is a unique path between every pair of points.
# 
# 
# Example 2:
# 
# Input: points = [[3,12],[-2,5],[-4,1]]
# Output: 18
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= points.length <= 1000
# 	-10⁶ <= xi, yi <= 10⁶
# 	All pairs (xi, yi) are distinct.
# 
 

class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        dist = [10**7] * n  # max possible distance is 4 * 10**6
        visited = [False] * n
        dist[0] = 0
        total = 0

        for _ in range(n):
            u = -1
            for v in range(n):
                if visited[v]:
                    continue
                if u == -1 or dist[v] < dist[u]:
                    u = v
            visited[u] = True
            total += dist[u]

            ux, uy = points[u]
            for v in range(n):
                if visited[v]:
                    continue
                px, py = points[v]
                d = abs(ux - px) + abs(uy - py)
                dist[v] = min(dist[v], d)
        return total
