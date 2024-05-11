class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

def find_lca(root, n1, n2):
    if root is None:
        return None
    
    if root.data == n1 or root.data == n2:
        return root
    
    left_lca = find_lca(root.left, n1, n2)
    right_lca = find_lca(root.right, n1, n2)

    if left_lca and right_lca:
        return root
    
    if left_lca is not None: 
        return left_lca
    else:
        return right_lca


tree = BinaryTree()

tree.root = Node(1)
tree.root.left = Node(12)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.left.right = Node(6)
tree.root.right.left = Node(5)
tree.root.right.right = Node(7)

print(find_lca(tree.root, 7, 5).data)