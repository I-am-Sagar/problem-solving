class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

def root_to_leaf_paths(root):
    all_paths = []

    def traverse(node, path):
        if node is None: 
            return 
        
        path.append(node.data)

        if node.left is None and node.right is None:
            all_paths.append(list(path))
        else:
            traverse(node.left, path)
            traverse(node.right, path)

        path.pop()
        
    traverse(root, [])
    return all_paths        


tree = BinaryTree()

tree.root = Node(1)
tree.root.left = Node(12)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(6)
tree.root.right.left = Node(5)
tree.root.right.right = Node(7)

print(root_to_leaf_paths(tree.root))