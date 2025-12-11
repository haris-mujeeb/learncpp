#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include <string>
#include <sstream>

template <typename T>
struct Node_2 {
    T data;
    Node_2<T>* next;
    Node_2<T>* prev;
    Node_2(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() {
        Node_2<T>* current = head;
        while (current) {
            Node_2<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void append(const T& data) {
        Node_2<T>* newNode = new Node_2<T>(data);
        if (!head) { // List is empty
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void prepend(const T& data) {
        Node_2<T>* newNode = new Node_2<T>(data);
        if (!head) { // List is empty
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(const T& key) {
        Node_2<T>* current = head;
        while (current) {
            if (current->data == key) {
                if (current->prev) { // Node_2 is not head
                    current->prev->next = current->next;
                } else { // Node_2 is head
                    head = current->next;
                }

                if (current->next) { // Node_2 is not tail
                    current->next->prev = current->prev;
                } else { // Node_2 is tail
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
    }

    std::string toStringForward() const {
        std::stringstream ss;
        Node_2<T>* current = head;
        while (current) {
            ss << current->data << " <-> ";
            current = current->next;
        }
        ss << "nullptr";
        return ss.str();
    }

    std::string toStringBackward() const {
        std::stringstream ss;
        Node_2<T>* current = tail;
        while (current) {
            ss << current->data << " <-> ";
            current = current->prev;
        }
        ss << "nullptr";
        return ss.str();
    }

    // Helper for testing
    const Node_2<T>* getHead() const { return head; }

private:
    Node_2<T>* head;
    Node_2<T>* tail;
};

#endif // DOUBLY_LINKED_LIST_HPP