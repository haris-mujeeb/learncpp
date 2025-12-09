#include <iostream>

struct Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr){}
};

class SinglyLinkedList
{
private:
    Node *head;
public:
    SinglyLinkedList() : head(nullptr){}
    void add(int data);
    void print();
};