class TrieNode:
    def __init__(self):
        # Initialize a node with children as an empty dictionary and end_of_word flag as False
        self.children = {}
        self.end_of_word = False

class Trie:
    def __init__(self):
        # Initialize the Trie with a root node
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        # Insert a word into the Trie
        node = self.root
        for char in word:
            if char not in node.children:
                # If the character is not a child of the current node, add it
                node.children[char] = TrieNode()
            # Move to the child node
            node = node.children[char]
        # After inserting all characters, mark the end of the word
        node.end_of_word = True

    def search(self, word: str) -> bool:
        # Search for a word in the Trie
        node = self.root
        for char in word:
            if char not in node.children:
                # If the character is not found, return False
                return False
            # Move to the child node
            node = node.children[char]
        # Return True if the end_of_word flag is set, meaning the word is found
        return node.end_of_word

    def startsWith(self, prefix: str) -> bool:
        # Check if there is any word in the Trie that starts with the given prefix
        node = self.root
        for char in prefix:
            if char not in node.children:
                # If the character is not found, return False
                return False
            # Move to the child node
            node = node.children[char]
        # Return True if the prefix is found
        return True

# Example usage
# # Your Trie object will be instantiated and called as such:
obj = Trie()
obj.insert("apple")
print(obj.search("apple"))   # return True
print(obj.search("app"))     # return False
print(obj.startsWith("app")) # return True
obj.insert("app")
print(obj.search("app"))     # return True
