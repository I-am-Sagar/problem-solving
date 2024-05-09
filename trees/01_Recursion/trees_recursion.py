from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    # P1: sum of all nodes in BT
    def sum_of_nodes(self, root):
        if root is None:
            return 0
        return root.data + self.sum_of_nodes(root.left) + self.sum_of_nodes(root.right)
    
    # Wrapper
    def sum(self):
        return self.sum_of_nodes(self.root)
    
    # P2: Height of the tree
    def height_of_tree(self, root):
        if root is None:
            return 0
        return 1 + max(self.height_of_tree(root.left), self.height_of_tree(root.right))
    
    # P3: Finding the max element
    def max_element(self, root):
        if root is None:
            return 0
        return max(root.data, self.max_element(root.left), self.max_element(root.right))
    
    # P4: Check if the node exists or not
    def search(self, root, key):
        if root is None: 
            return False
        
        if root.data == key:
            return True
        
        return self.search(root.left, key) or self.search(root.right, key)
    
    # P5-P8: Check if a tree is of particular type
    def is_full(self, root):
        if root is None:
            return True
        
        if root.left is None and root.right is None: 
            return True
        
        if root.left is not None and root.right is not None: 
            return self.is_full(root.left) and self.is_full(root.right)

        return False
    
    def is_skewed(self, root):
        if root is None or (root.left is None and root.right is None):
            return True
        
        if root.left is None:
            return self.is_skewed(root.right)
        
        if root.right is None:
            return self.is_skewed(root.left)
        
        return False

    def count_nodes(self, root):
        if root is None:
            return 0
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)

    def is_perfect(self):
        height = self.height_of_tree(self.root)
        count = self.count_nodes(self.root)
        return count == 2**height - 1
    
    # Suggested:
    # 1. Get the height of tree
    # 2. Go on a level order traversal. Wait for the moment, till you find the first incomplete node (leaf node). 
    # If your incomplete node is on level < height - 1, tree is incomplete. 

    # Recursion:
    def is_complete(self, root, index, node_count):
        if root is None:
            return True
        
        if index >= node_count:
            return False
        
        return self.is_complete(root.left, 2*index + 1, node_count) and self.is_complete(root.right, 2*index+2, node_count)

tree = BinaryTree()

tree.root = Node(1)
tree.root.left = Node(12)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(6)
tree.root.right.left = Node(5)
tree.root.right.right = Node(7)


print(tree.sum())
print(tree.height_of_tree(tree.root))
print(tree.max_element(tree.root))
print(tree.search(tree.root, 4))
print(tree.is_full(tree.root))
print(tree.is_skewed(tree.root))
print(tree.is_perfect())
print(tree.is_complete(tree.root, 0, tree.count_nodes(tree.root)))