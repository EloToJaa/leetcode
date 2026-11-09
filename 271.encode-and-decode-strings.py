# Category: algorithms
# Level: Medium

# Design an algorithm to encode a list of strings to a string. The encoded
# string is then sent over the network and is decoded back to the original list
# of strings.
#
# Implement the encode and decode methods:
#
# 	string encode(List<string> strs): encodes a list of strings to a single string.
# 	List<string> decode(string s): decodes a single string back to the list of strings.
#
# Example 1:
#
# Input: ["neet","code","love","you"]
# Output: ["neet","code","love","you"]
#
# Example 2:
#
# Input: ["we","say",":","yes"]
# Output: ["we","say",":","yes"]
#
# Constraints:
#
# 	0 <= strs.length < 100
# 	0 <= strs[i].length < 200
# 	strs[i] contains any possible characters out of 256 valid ASCII characters.


class Solution:
    def encode(self, strs: List[str]) -> str:
        return "".join(f"{len(s)}#{s}" for s in strs)

    def decode(self, s: str) -> List[str]:
        result = []
        i = 0
        while i < len(s):
            j = s.index("#", i)
            length = int(s[i:j])
            result.append(s[j + 1 : j + 1 + length])
            i = j + 1 + length
        return result
