# Category: algorithms
# Level: Hard


# There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.
#
# You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are sorted lexicographically by the rules of this new language.
#
# If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".
#
# Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.
#
#
# Example 1:
#
# Input: words = ["wrt","wrf","er","ett","rftt"]
# Output: "wertf"
#
#
# Example 2:
#
# Input: words = ["z","x"]
# Output: "zx"
#
#
# Example 3:
#
# Input: words = ["z","x","z"]
# Output: ""
# Explanation: The order is invalid, so return "".
#
#
# Constraints:
#
#
# 	1 <= words.length <= 100
# 	1 <= words[i].length <= 100
# 	words[i] consists of only lowercase English letters.


class Solution:
    def alienOrder(self, words: list[str]) -> str:
        graph: dict[str, set[str]] = {c: set() for word in words for c in word}

        for w1, w2 in zip(words, words[1:]):
            if len(w1) > len(w2) and w1.startswith(w2):
                return ""

            for a, b in zip(w1, w2):
                if a == b:
                    continue
                graph[a].add(b)
                break

        state = {c: 0 for c in graph}
        postorder: list[str] = []

        def dfs(c: str) -> bool:
            if state[c] == 1:
                return False
            if state[c] == 2:
                return True

            state[c] = 1
            for nxt in graph[c]:
                if not dfs(nxt):
                    return False
            state[c] = 2
            postorder.append(c)
            return True

        for c in graph:
            if not dfs(c):
                return ""

        return "".join(reversed(postorder))
