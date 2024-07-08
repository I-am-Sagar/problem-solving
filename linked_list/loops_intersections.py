from crud_ll import LinkedList, Node

class LinkedListLoop(LinkedList):

    def detect_loop(self):
        slow = self.head
        fast = self.head

        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        
        return False


    def remove_loop(self):
        slow = self.head
        fast = self.head

        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if (slow == fast):    # You are at meeting point
                # We have found the loop
                fast = self.head

                # We will increment both by 1 step, till their next matches
                while slow.next != fast.next:
                    fast = fast.next
                    slow = slow.next

                # slow is just one step before the looping point
                slow.next = None
                return True
            
        return False
    

    def find_intersection(self, l2):
        visited  = set()

        current = self.head
        while current:
            visited.add(current)
            current = current.next

        current = l2.head
        while current:
            if current in visited:
                return current
            current = current.next

        return None

def main():
    ll = LinkedListLoop()

    for i in range(1, 7):
        ll.append(i)
    ll.print()   # 1 2 3 4 5 6

    print(ll.detect_loop())   # false

    # loop is created
    last_node = ll.head
    while last_node.next:
        last_node = last_node.next
    last_node.next = ll.head.next.next.next   # 6 is pointing back to 4

    print(ll.detect_loop())  # true

    ll.remove_loop()  

    print(ll.detect_loop())  # false


    l1 = LinkedListLoop()
    l2 = LinkedListLoop()
    intersection_node = Node(4)

    l1.append(1)
    l1.append(2)
    l1.append(3)
    l1.head.next.next.next = intersection_node
    l1.append(5)
    l1.append(6)
    l1.append(8)

    l2.append(2)
    l2.head.next = intersection_node

    l1.print()
    l2.print()

    ins_node = l1.find_intersection(l2)

    # Print will give you error if no intersection exists, 
    # because you will be trying to find None.data which doesnt make sense
    print(ins_node.data, ins_node)    



if __name__ == "__main__":
    main()