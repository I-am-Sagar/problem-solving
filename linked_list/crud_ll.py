class Node:
    # Data  (In py, the data is always put in the __init__ function)
    def __init__(self, d):
        self.data = d
        self.next = None

class LinkedList:
    # Data
    def __init__(self):
        self.head = None

    # Functions

    # --------------- CREATE ------------------

    # Adds node with data at the end
    def append(self, data):
        new_node = Node(data)
        # If the linked list is empty
        if self.head is None:
            self.head = new_node
            return
        # If the head is not empty
        last_node = self.head
        while last_node.next:
            last_node = last_node.next  
        last_node.next = new_node


    # Insert a node at a specific position
    def insert(self, data, pos):
        new_node = Node(data)
        # Add at the start
        if pos == 0:
            new_node.next = self.head
            self.head = new_node
            return 
        
        current_node = self.head
        count = 1
        while current_node and count < pos:
            current_node = current_node.next
            count += 1

        # If your current node is null, you must have gone beyond the list
        if not current_node:
            print("Error: Your position is longer than the linked list.")
            return

        new_node.next = current_node.next
        current_node.next = new_node

    # ------------------ READ -------------------------

    def print(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=" ")
            current_node = current_node.next
        print()

    # ------------------ UPDATE -----------------------

    def replace(self, new_data, pos):
        current_node = self.head
        count = 0
        while current_node and count < pos:
            current_node = current_node.next
            count += 1

        # If your current node is null, you must have gone beyond the list
        if not current_node:
            print("Error: Your position is longer than the linked list.")
            return
    
        current_node.data = new_data
    
    # ----------------- DELETE -------------------------
    
    def delete(self, value):
        current_node = self.head

        # If the first element needs to be deleted
        if current_node and current_node.data == value:
            self.head = current_node.next
            current_node = None
            return

        prev_node = None
        while current_node and current_node.data != value:
            prev_node = current_node
            current_node = current_node.next

        if current_node is None:
            print("Error: Value to be deleted not found.")
            return
        
        prev_node.next = current_node.next
        current_node = None
    
    # ------------ Overriding Python's existing functions -------------------

    def __len__(self):
        length = 0
        current_node = self.head
        while current_node:
            current_node = current_node.next
            length += 1
        return length
    
        
def main():
    ll = LinkedList()

    ll.append(1)
    ll.append(2)
    for i in range(3, 6):
        ll.append(i)

    ll.print()

    ll.insert(6, 2)
    ll.insert(7, 4)

    ll.print()

    ll.replace(16, 2)

    ll.print()

    ll.delete(16)
    ll.delete(5)
    ll.delete(7)

    ll.print()

    print(len(ll))

if __name__ == "__main__":
    main()