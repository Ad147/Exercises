// LeetCode707-DesignLinkedList.cpp
// Ad
// Update: 19Mar13

/* -----------------------------------------------------------------------------

707. Design Linked List
Easy
Linked list, Design

Design your implementation of the linked list.
You can choose to use the singly linked list or the doubly linked list.
A node in a singly linked list should have two attributes: val and next.
val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list.
Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

- get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
- addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
- addAtTail(val) : Append a node of value val to the last element of the linked list.
- addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
- deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.

Example:
----------------------------------------
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
----------------------------------------

Note:
- All values will be in the range of [1, 1000].
- The number of operations will be in the range of [1, 1000].
- Please do not use the built-in LinkedList library.

----------------------------------------------------------------------------- */

#include <iostream>

// Solution-0 ==================================================================

// Runtime: 52 ms, faster than 91.98% of C++ online submissions for Design Linked List.
// Memory Usage: 19.7 MB, less than 23.75% of C++ online submissions for Design Linked List.
// Doubly linked list.

class MyLinkedList
{
  private:
    struct Node
    {
        int val;
        Node *prev;
        Node *next;

        Node(int v = -1, Node *p = nullptr, Node *n = nullptr) : val{v}, prev{p}, next{n} {}
    };

    Node *head;
    Node *tail;
    int len;

  public:
    /** Initialize your data structure here. */
    MyLinkedList() : len{0}
    {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (isIndexInvalid(index))
            return -1;

        Node *p = findNodeAtIndex(index);
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) { addAtIndex(0, val); }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        tail->prev = tail->prev->next = new Node{val, tail->prev, tail};
        ++len;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index == len)
        {
            addAtTail(val);
            return;
        }
        if (isIndexInvalid(index))
            return;

        Node *p = findNodeAtIndex(index);
        p->prev = p->prev->next = new Node{val, p->prev, p};
        ++len;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (isIndexInvalid(index))
            return;

        Node *p = findNodeAtIndex(index);
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        --len;
    }

  private:
    bool isIndexInvalid(int index) { return (index >= len || index < 0); }

    Node *findNodeAtIndex(int index)
    {
        Node *p = head->next;
        for (int i = 0; i < index; ++i)
            p = p->next;

        return p;
    }
};

// Solution-Alter ====================================================================

// Singly linked list.

class MyLinkedList2
{
  public:
    MyLinkedList2() : siz{0}, head{nullptr}, tail{nullptr} {};

    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);

  private:
    struct Node
    {
        Node(int v = 0, Node *n = nullptr)
            : value{v}, next{n} {}

        int value;
        Node *next;
    };

    int siz;
    Node *head;
    Node *tail;
};

// member functions ------------------------------------------------------------

int MyLinkedList2::get(int index)
{
    if (index >= siz || index < 0)
        return -1;

    auto p = head;
    for (size_t i = {0}; i != index; ++i)
        p = p->next;

    return p->value;
}

void MyLinkedList2::addAtHead(int val)
{
    auto temp = head;
    head = new Node(val, temp);
    if (tail == nullptr)
        tail = head;
    ++siz;
}

void MyLinkedList2::addAtTail(int val)
{
    auto temp = tail;
    tail = new Node(val, nullptr);
    if (head == nullptr)
        head = tail;
    else
        temp->next = tail;
    ++siz;
}

void MyLinkedList2::addAtIndex(int index, int val)
{
    if (index > siz || index < 0)
        return;
    else if (index == 0)
    {
        addAtHead(val);
        return;
    }
    else if (index == siz)
    {
        addAtTail(val);
        return;
    }

    auto p = head;
    for (size_t i = {0}; i != index - 1; ++i)
        p = p->next;

    auto temp = p;
    p = new Node(val, temp->next);
    temp->next = p;
    ++siz;
}

void MyLinkedList2::deleteAtIndex(int index)
{
    if (index >= siz || index < 0)
        return;
    else if (index == 0)
    {
        auto temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
        --siz;
        return;
    }

    auto p = head;
    for (int i = {0}; i != index - 1; ++i)
        p = p->next;

    auto temp = p->next;
    p->next = temp->next;

    delete temp;
    --siz;
}

// test ========================================================================

int main(int argc, char *argv[])
{
    MyLinkedList *linkedList = new MyLinkedList();
    std::cout << linkedList->get(0) << std::endl;
    linkedList->addAtIndex(1, 2);
    std::cout << linkedList->get(0) << linkedList->get(1) << linkedList->get(2) << std::endl;
    linkedList->addAtIndex(0, 1);
    std::cout << linkedList->get(0) << linkedList->get(1) << linkedList->get(2) << std::endl;

    // pause
    system("pause");
    return 0;
}
