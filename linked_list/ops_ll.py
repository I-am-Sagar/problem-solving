from loops_intersections import LinkedListLoop

class LinkedListOps(LinkedListLoop):

    # ---------------- REVERSE ---------------------
    def reverse(self):
        prev_node = None
        current_node = self.head
        next_node = None

        while current_node:
            next_node = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = next_node

        self.head = prev_node

    # ------------------- SORTING -------------------
    def middle(self, head):
        if not head:
            return head

        slow = head
        fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        return slow
    
    
    def merge(self, left, right):
        result = None

        if not left:
            return right
        
        if not right:
            return left
        
        if left.data <= right.data:
            result = left
            result.next = self.merge(left.next, right)
        else:
            result = right
            result.next = self.merge(left, right.next)

        return result

    
    # Mergesort implementation
    def merge_sort(self, head):
        # Base condition (0 or 1 node): return
        if not head or not head.next: 
            return head
        
        # Get the middle node
        middle_node = self.middle(head)

        # Split the linked lists
        right_half = middle_node.next
        middle_node.next = None
        left_half = head

        left = self.merge_sort(left_half)
        right = self.merge_sort(right_half)

        result = self.merge(left, right)
        return result
    

    # Wrapper function that manipulates the head
    def sort(self):
        self.head = self.merge_sort(self.head)
    

def main():
    ll = LinkedListOps()

    for i in range(1, 7):
        ll.append(i)
    ll.print()
    ll.reverse()
    ll.print()

    l1 = LinkedListOps()

    l1.append(4)
    l1.append(3)
    l1.append(7)
    l1.append(2)
    l1.append(9)
    l1.append(5)
    l1.append(1)
    l1.append(6)
    l1.append(8)

    l1.print()
    l1.sort()
    l1.print()

    # print(l1.detect_loop())


if __name__ == "__main__":
    main()