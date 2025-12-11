class Node:
    def __init__(self, data):
        self.data = data  # Store the data
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.head = None  # Initialize the head of the list

    def append(self, data):
        """Add a node at the end of the list."""
        new_node = Node(data)
        if not self.head:  # If the list is empty
            self.head = new_node
            return
        last = self.head
        while last.next:  # Traverse to the last node
            last = last.next
        last.next = new_node  # Link the new node
        new_node.prev = last  # Set the previous pointer of the new node

    def prepend(self, data):
        """Add a node at the beginning of the list."""
        new_node = Node(data)
        if not self.head:  # If the list is empty
            self.head = new_node
            return
        new_node.next = self.head  # Link the new node to the head
        self.head.prev = new_node  # Set the previous pointer of the head
        self.head = new_node  # Update the head to the new node

    def delete(self, key):
        """Delete a node by its value."""
        current = self.head
        while current:  # Traverse the list
            if current.data == key:  # If the node to be deleted is found
                if current.prev:  # If it's not the first node
                    current.prev.next = current.next
                if current.next:  # If it's not the last node
                    current.next.prev = current.prev
                if current == self.head:  # If it's the head node
                    self.head = current.next
                return
            current = current.next

    def display_forward(self):
        """Display the list from head to tail."""
        current = self.head
        while current:
            print(current.data, end=" <-> ")
            current = current.next
        print("None")

    def display_backward(self):
        """Display the list from tail to head."""
        current = self.head
        if not current:  # If the list is empty
            print("None")
            return
        while current.next:  # Traverse to the last node
            current = current.next
        while current:  # Traverse backward
            print(current.data, end=" <-> ")
            current = current.prev
        print("None")

# Example usage
if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.append(1)
    dll.append(2)
    dll.append(3)
    dll.prepend(0)

    print("Display forward:")
    dll.display_forward()  # Output: 0 <-> 1 <-> 2 <-> 3 <-> None

    print("Display backward:")
    dll.display_backward()  # Output: 3 <-> 2 <-> 1 <-> 0 <-> None

    dll.delete(2)
    print("After deleting 2:")
    dll.display_forward()  # Output: 0 <-> 1 <-> 3 <-> None
