# Category: algorithms
# Level: Medium
# Percent: 48.710747%



# Design a data structure that supports adding new words and finding if a string matches any previously added string.
# 
# Implement the WordDictionary class:
# 
# 
# 	WordDictionary() Initializes the object.
# 	void addWord(word) Adds word to the data structure, it can be matched later.
# 	bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
# 
# 
#  
# Example:
# 
# Input
# ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
# [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
# Output
# [null,null,null,null,false,true,true,true]
# 
# Explanation
# WordDictionary wordDictionary = new WordDictionary();
# wordDictionary.addWord("bad");
# wordDictionary.addWord("dad");
# wordDictionary.addWord("mad");
# wordDictionary.search("pad"); // return False
# wordDictionary.search("bad"); // return True
# wordDictionary.search(".ad"); // return True
# wordDictionary.search("b.."); // return True
# 
# 
#  
# Constraints:
# 
# 
# 	1 <= word.length <= 25
# 	word in addWord consists of lowercase English letters.
# 	word in search consist of '.' or lowercase English letters.
# 	There will be at most 2 dots in word for search queries.
# 	At most 10⁴ calls will be made to addWord and search.
# 
 

class WordDictionary:
    def __init__(self):
        self.children = [{}]
        self.endings = [False]

    def addWord(self, word: str) -> None:
        node = 0
        for char in word:
            if char not in self.children[node]:
                self.children[node][char] = len(self.children)
                self.children.append({})
                self.endings.append(False)
            node = self.children[node][char]
        self.endings[node] = True

    def search(self, word: str) -> bool:
        def dfs(i, node):
            if i == len(word):
                return self.endings[node]

            if word[i] == '.':
                for child in self.children[node].values():
                    if dfs(i + 1, child):
                        return True
                return False
            
            if word[i] in self.children[node]:
                return dfs(i + 1, self.children[node][word[i]])
            return False
        
        return dfs(0, 0)



# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
