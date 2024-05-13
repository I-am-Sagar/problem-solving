class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

def root_to_node_path(root, key):
    ans = []
    
    def traverse(node, key, path):
        nonlocal ans
        
        if node is None:
            return

        path.append(node.data)

        if node.data == key:
            ans = path.copy()
            return
        else:
            traverse(node.left, key, path)
            traverse(node.right, key, path)

        path.pop()

    traverse(root, key, [])
    return ans


tree = BinaryTree()

tree.root = Node(1)
tree.root.left = Node(12)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(6)
tree.root.right.left = Node(5)
tree.root.right.right = Node(7)

print(root_to_node_path(tree.root, 7))