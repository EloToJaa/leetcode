# Category: algorithms
# Level: Hard
# Percent: 38.636673%



# Given an m x n board of characters and a list of strings words, return all words on the board.
# 
# Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
# 
#  
# Example 1:
# 
# Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
# Output: ["eat","oath"]
# 
# 
# Example 2:
# 
# Input: board = [["a","b"],["c","d"]], words = ["abcb"]
# Output: []
# 
# 
#  
# Constraints:
# 
# 
# 	m == board.length
# 	n == board[i].length
# 	1 <= m, n <= 12
# 	board[i][j] is a lowercase English letter.
# 	1 <= words.length <= 3 * 10⁴
# 	1 <= words[i].length <= 10
# 	words[i] consists of lowercase English letters.
# 	All the strings of words are unique.
# 
 

class Solution:
    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        trie_child = [{}]
        trie_end = [False]

        for word in words:
            node = 0
            for c in word:
                if c not in trie_child[node]:
                    trie_child[node][c] = len(trie_child)
                    trie_child.append({})
                    trie_end.append(False)
                node = trie_child[node][c]
            trie_end[node] = True
        
        res, visit = set(), set()
        R, C = len(board), len(board[0])

        def dfs(r, c, node, word):
            dirs = ((-1, 0), (1, 0), (0, -1), (0, 1))

            if not (0 <= r < R and 0 <= c < C):
                return
            if (r, c) in visit:
                return

            char = board[r][c]
            if char not in trie_child[node]:
                return

            visit.add((r, c))

            node = trie_child[node][char]
            word += char
            if trie_end[node]:
                res.add(word)
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                dfs(nr, nc, node, word)
            visit.remove((r, c))

        for r in range(R):
            for c in range(C):
                if board[r][c] in trie_child[0]:
                    dfs(r, c, 0, "")
        
        return list(res)
