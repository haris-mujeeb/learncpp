#include <gtest/gtest.h>
#include <string>
#include "singly_linked_list.hpp"
#include "doubly_linked_list.hpp"

class SinglyLinkedListTest : public ::testing::Test {
protected:
    SinglyLinkedList<int> int_list;
    SinglyLinkedList<std::string> string_list;
};

TEST_F(SinglyLinkedListTest, InitialState) {
  EXPECT_EQ(int_list.toString(), "nullptr");
}

TEST_F(SinglyLinkedListTest, AddOneNode) {
    int_list.add(10);
    EXPECT_EQ(int_list.toString(), "10->nullptr");
}

TEST_F(SinglyLinkedListTest, AddMultipleNodes) {
    int_list.add(10);
    int_list.add(20);
    int_list.add(30);
    // add prepends, so the order is reversed
    EXPECT_EQ(int_list.toString(), "30->20->10->nullptr");
}

TEST_F(SinglyLinkedListTest, WorksWithStrings) {
    string_list.add("World");
    string_list.add("Hello");
    EXPECT_EQ(string_list.toString(), "Hello->World->nullptr");
}

class DoublyLinkedListTest : public ::testing::Test {
protected:
    DoublyLinkedList<int> int_dll;
    DoublyLinkedList<std::string> string_dll;
};

TEST_F(DoublyLinkedListTest, InitialState) {
    EXPECT_EQ(int_dll.toStringForward(), "nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "nullptr");
}

TEST_F(DoublyLinkedListTest, Append) {
    int_dll.append(10);
    int_dll.append(20);
    EXPECT_EQ(int_dll.toStringForward(), "10 <-> 20 <-> nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "20 <-> 10 <-> nullptr");
}

TEST_F(DoublyLinkedListTest, Prepend) {
    int_dll.prepend(10);
    int_dll.prepend(20);
    EXPECT_EQ(int_dll.toStringForward(), "20 <-> 10 <-> nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "10 <-> 20 <-> nullptr");
}

TEST_F(DoublyLinkedListTest, MixedAppendPrepend) {
    int_dll.append(20);
    int_dll.prepend(10);
    int_dll.append(30);
    EXPECT_EQ(int_dll.toStringForward(), "10 <-> 20 <-> 30 <-> nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "30 <-> 20 <-> 10 <-> nullptr");
}

TEST_F(DoublyLinkedListTest, DeleteNode) {
    int_dll.append(10);
    int_dll.append(20);
    int_dll.append(30);

    // Delete middle
    int_dll.deleteNode(20);
    EXPECT_EQ(int_dll.toStringForward(), "10 <-> 30 <-> nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "30 <-> 10 <-> nullptr");

    // Delete head
    int_dll.deleteNode(10);
    EXPECT_EQ(int_dll.toStringForward(), "30 <-> nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "30 <-> nullptr");

    // Delete only node (which is also the tail)
    int_dll.deleteNode(30);
    EXPECT_EQ(int_dll.toStringForward(), "nullptr");
    EXPECT_EQ(int_dll.toStringBackward(), "nullptr");
}

TEST_F(DoublyLinkedListTest, DeleteNonExistent) {
    int_dll.append(10);
    int_dll.deleteNode(99);
    EXPECT_EQ(int_dll.toStringForward(), "10 <-> nullptr");
}

TEST_F(DoublyLinkedListTest, WorksWithStrings) {
    string_dll.append("B");
    string_dll.prepend("A");
    string_dll.append("C");
    EXPECT_EQ(string_dll.toStringForward(), "A <-> B <-> C <-> nullptr");
    string_dll.deleteNode("B");
    EXPECT_EQ(string_dll.toStringForward(), "A <-> C <-> nullptr");
    EXPECT_EQ(string_dll.toStringBackward(), "C <-> A <-> nullptr");
}