# Category: algorithms
# Level: Medium

# You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
#
# Return the number of connected components in the graph.
#
# Example 1:
# Input: n = 5, edges = [[0,1],[1,2],[3,4]]
# Output: 2
# Example 2:
# Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
# Output: 1
#
# Constraints:
#
# 	1 <= n <= 2000
# 	1 <= edges.length <= 5000
# 	edges[i].length == 2
# 	0 <= ai <= bi < n
# 	ai != bi
# 	There are no repeated edges.


class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        rep = [i for i in range(n)]
        size = [0] * n
        
        def find(a):
            while rep[a] != a:
                rep[a] = rep[rep[a]]
                a = rep[a]
            return a

        def union(a, b):
            a, b = find(a), find(b)
            if a == b:
                return False
            if size[a] > size[b]:
                a, b = b, a
            size[b] += size[a]
            rep[a] = rep[b]
            return True
        
        for u, v in edges:
            union(u, v)

        res = set()
        for i in range(n):
            res.add(find(i))
        return len(res)
