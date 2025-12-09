#include "doubly_linked_list.hpp"

// Node constructor
Node2::Node2(int value) : data(value), next(nullptr), prev(nullptr) {}

// DoublyLinkedList constructor
DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

// Method to append a node at the end of the list
void DoublyLinkedList::append(int data) {
    Node2* newNode = new Node2(data);
    if (!head) { // If the list is empty
        head = newNode;
        return;
    }
    Node2* last = head;
    while (last->next) { // Traverse to the last node
        last = last->next;
    }
    last->next = newNode; // Link the new node
    newNode->prev = last; // Set the previous pointer of the new node
}

// Method to prepend a node at the beginning of the list
void DoublyLinkedList::prepend(int data) {
    Node2* newNode = new Node2(data);
    if (!head) { // If the list is empty
        head = newNode;
        return;
    }
    newNode->next = head; // Link the new node to the head
    head->prev = newNode; // Set the previous pointer of the head
    head = newNode;       // Update the head to the new node
}

// Method to delete a node by its value
void DoublyLinkedList::deleteNode(int key) {
    Node2* current = head;
    while (current) { // Traverse the list
        if (current->data == key) { // If the node to be deleted is found
            if (current->prev) { // If it's not the first node
                current->prev->next = current->next;
            }
            if (current->next) { // If it's not the last node
                current->next->prev = current->prev;
            }
            if (current == head) { // If it's the head node
                head = current->next;
            }
            delete current; // Free the memory
            return;
        }
        current = current->next;
    }
}

// Method to display the list from head to tail
void DoublyLinkedList::displayForward() {
    Node2* current = head;
    while (current) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Method to display the list from tail to head
void DoublyLinkedList::displayBackward() {
    Node2* current = head;
    if (!current) { // If the list is empty
        std::cout << "nullptr" << std::endl;
        return;
    }
    while (current->next) { // Traverse to the last node
        current = current->next;
    }
    while (current) { // Traverse backward
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "nullptr" << std::endl;
}

// Destructor to free the memory
DoublyLinkedList::~DoublyLinkedList() {
  Node2* current = head;
  while (current) {
      Node2* nextNode = current->next;
      delete current;
      current = nextNode;
  }
}