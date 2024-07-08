class TrieNode:
    def __init__(self):
        # Initialize a TrieNode with children as a dictionary and is_end flag as False
        self.children = {}
        self.is_end = False

class Solution:
    def __init__(self):
        # Initialize a root TrieNode
        self.new_node = TrieNode()
    
    def check(self, word: str) -> str:
        # Check the shortest prefix of the word in the Trie
        t = self.new_node
        s = ""
        
        for char in word:
            if char not in t.children:
                break
            s += char
            t = t.children[char]
            if t.is_end:
                return s
        
        return word
    
    def insert(self, word: str) -> None:
        # Insert a word into the Trie
        temp = self.new_node
        
        for char in word:
            if char not in temp.children:
                temp.children[char] = TrieNode()
            temp = temp.children[char]
        
        temp.is_end = True
    
    def replaceWords(self, dict, sentence: str) -> str:
        # Build the Trie from the dictionary and replace words in the sentence
        for word in dict:
            self.insert(word)
        
        words = sentence.split()
        ans = ""
        
        for word in words:
            ans += self.check(word) + " "
        
        return ans.strip()



# Example usage
solution = Solution()
dictionary = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
print(solution.replaceWords(dictionary, sentence))  # Output: "the cat was rat by the bat"