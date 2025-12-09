#include "singly_linked_list.hpp"

void SinglyLinkedList::add(int data)
{
  Node* newNode = new Node(data);

  if (head==nullptr) {
      head = newNode;
  } else {  
    newNode->next = head;
    head = newNode;
  }
}

void SinglyLinkedList::print(){
  Node* current = head;
  while(current != nullptr) {
    std::cout << current->data << "->";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

