#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

class Node2 {
public:
    int data;        // Data field
    Node2* next;     // Pointer to the next node
    Node2* prev;     // Pointer to the previous node

    Node2(int value);
};

class DoublyLinkedList {
private:
    Node2* head;      // Pointer to the head of the list

public:
    DoublyLinkedList(); // Constructor
    ~DoublyLinkedList(); // Destructor

    void append(int data); // Method to append a node at the end of the list
    void prepend(int data); // Method to prepend a node at the beginning of the list
    void deleteNode(int key); // Method to delete a node by its value
    void displayForward(); // Method to display the list from head to tail
    void displayBackward(); // Method to display the list from tail to head
};

#endif // DOUBLY_LINKED_LIST_H
