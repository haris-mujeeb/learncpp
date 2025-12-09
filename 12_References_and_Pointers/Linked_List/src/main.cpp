#include <iostream>
// #include "singly_linked_list.hpp"
// #include "doubly_linked_list.hpp"

class Node3 {
public:
	int data;
	Node3* next;
	Node3* prev;
	Node3(int value) : data(value), next(nullptr), prev(nullptr){}
};

class Linklist {
	Node3* head;
	Node3* tail;
public:
	Linklist() { head = nullptr; tail = nullptr;}

  void insertathead(int data) {
		Node3* newnode = new Node3(data);
		if (head==nullptr) {
			head = tail = newnode;
		}
		else {
			head->next = newnode;
			newnode->prev = head;
			head = newnode;
		}
	}

  void insertAtEnd(int value) {
		Node3* newNode = new Node3(value);
		if (!tail) {
			head = tail = newNode;
			return;
		}
		else {
			tail->prev = newNode;
			newNode->next = tail;
			tail = newNode;
		}
	}

  void displayhead() {
    Node3* current = head;
    while (current!=nullptr) {
      std::cout << current->data << " ";
      current = current->prev;
    }
    std::cout << std::endl;
  }
  
  void displaytail() {
    Node3* current = tail;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};


int main() {
	Linklist a;
	a.insertathead(2);
	a.insertathead(5);
	a.insertAtEnd(7);
	a.displayhead();
	a.displaytail();

	return 0;
}


// int main(){
//   SinglyLinkedList myList;
//   myList.add(1);  
//   myList.add(2);  
//   myList.add(3);

//   myList.print();

//   DoublyLinkedList myDList;
//   myDList.append(1);
//   myDList.append(2);
//   myDList.append(3);
//   myDList.prepend(0);

//   std::cout << "Display forward:" << std::endl;
//   myDList.displayForward(); // Output: 0 <-> 1 <-> 2 <-> 3 <-> nullptr

//   std::cout << "Display backward:" << std::endl;
//   myDList.displayBackward(); // Output: 0 <-> 1 <-> 2 <-> 3 <-> nullptr


//   myDList.deleteNode(2);
//   std::cout << "After deleting 2:" << std::endl;
//   myDList.displayForward(); // Output: 0 <-> 1 <-> 3 <-> nullptr

//   return 0;
// }