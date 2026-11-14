# Category: algorithms
# Level: Medium

# You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.
#
# Return true if the edges of the given graph make up a valid tree, and false otherwise.
#
# Example 1:
# Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
# Output: true
# Example 2:
# Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
# Output: false
#
# Constraints:
#
# 	1 <= n <= 2000
# 	0 <= edges.length <= 5000
# 	edges[i].length == 2
# 	0 <= ai, bi < n
# 	ai != bi
# 	There are no self-loops or repeated edges.


class Solution:
    def validTree(self, n: int, edges: list[list[int]]) -> bool:
        if n - 1 != len(edges):
            return False

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
            if not union(u, v):
                return False
        return True
