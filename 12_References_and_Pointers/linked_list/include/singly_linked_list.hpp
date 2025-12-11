#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <string>
#include <sstream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class SinglyLinkedList {
public:
    SinglyLinkedList() : head(nullptr) {}
    ~SinglyLinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void add(const T& data) {
        // This method prepends a new node to the beginning of the list.
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    std::string toString() const {
        std::stringstream ss;
        Node<T>* current = head;
        while(current != nullptr) {
            ss << current->data << "->";
            current = current->next;
        }
        ss << "nullptr";
        return ss.str();
    }

    // Helper for testing
    const Node<T>* getHead() const { return head; }

private:
    Node<T>* head;
};

#endif // SINGLY_LINKED_LIST_HPP