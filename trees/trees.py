from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def level_order_traversal(self):
        # Formalities/Edge Cases
        if self.root is None:
            return []

        result = []

        # Main logic
        q = deque()
        q.append(self.root)

        while q:
            level_nodes = []
            level_size = len(q)

            for _ in range(level_size):
                curr = q.popleft()
                # This is the place where you edit your elements
                level_nodes.append(curr.data)

                if curr.left:
                    q.append(curr.left)
                if curr.right:
                    q.append(curr.right)
            
            # This is the place where level shift happens
            result.append(level_nodes)

        return result
    
    def levels(self):
        result = self.level_order_traversal()
        return len(result)
    
    def preorder_traversal(self, root):
        # formalities
        if root is None:
            return []
        
        result = []
        result.append(root.data)
        result.extend(self.preorder_traversal(root.left))
        result.extend(self.preorder_traversal(root.right))
        return result

    def inorder_traversal(self, root):
        # formalities
        if root is None:
            return []
        
        result = []
        result.extend(self.inorder_traversal(root.left))
        result.append(root.data)
        result.extend(self.inorder_traversal(root.right))
        return result
    
    def postorder_traversal(self, root):
        # formalities
        if root is None:
            return []
        
        result = []
        result.extend(self.postorder_traversal(root.left))
        result.extend(self.postorder_traversal(root.right))
        result.append(root.data)
        return result

tree = BinaryTree()

tree.root = Node(1)
tree.root.left = Node(12)
tree.root.right = Node(3)
tree.root.left.left = Node(4)
tree.root.right.left = Node(5)
tree.root.right.left.right = Node(6)

print(tree.level_order_traversal())
print(tree.levels())
print(tree.preorder_traversal(tree.root))
print(tree.inorder_traversal(tree.root))
print(tree.postorder_traversal(tree.root))