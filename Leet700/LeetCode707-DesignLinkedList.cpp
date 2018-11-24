// LeetCode707-DesignLinkedList.cpp
// Ad
// Design your implementation of the linked list.
// You can choose to use the singly linked list or the doubly linked list.
// Implement these functions in your linked list class:
//  - get(index): get the value of the index-th node in the linked list. If the index is invalid, return -1.
//  - addAtHead(val): add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
//  - addAtTail(val): Append a node of value val to the last element of the linked list.
//  - addAtIndex(index, val): add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If the index is greater than the length, the node will not be inserted.
// deleteAtIndex(index): delete the index-th node in the linked list, if the index is valid.

#include <iostream>

// solution ====================================================================

// doubly linked list
// 44 ms (22%)
// -> 24 ms

class MyLinkedList
{
  public:
    // constructors
    MyLinkedList();
    // destructor
    ~MyLinkedList();

    // get the index-th value
    int get(int index);
    // add a node at head
    void addAtHead(int val) { addAtIndex(0, val); }
    // add a node at tail
    void addAtTail(int val) { addAtIndex(siz, val); }
    // add a node before the index-th node
    void addAtIndex(int index, int val);
    // delete the index-th node
    void deleteAtIndex(int index);

  private:
    struct Node
    {
        // constructor
        Node(int v = 0, Node *n = nullptr, Node *p = nullptr)
            : value{v}, next{n}, prev{p} {}

        int value;
        Node *next;
        Node *prev;
    };

    int siz;
    Node *head;
    Node *tail;
};

// member functions ------------------------------------------------------------

MyLinkedList::MyLinkedList()
{
    siz = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

MyLinkedList::~MyLinkedList()
{
    while (siz != 0)
        deleteAtIndex(0);
    delete head;
    delete tail;
}

int MyLinkedList::get(int index)
{
    if (index < 0 || index >= siz)
        return -1;

    Node *p = head->next;
    for (int i = {0}; i != index; ++i)
        p = p->next;

    return p->value;
}

void MyLinkedList::addAtIndex(int index, int val)
{
    if (index < 0 || index > siz)
        return;

    Node *p = head->next;
    for (int i = {0}; i != index; ++i)
        p = p->next;

    p->prev->next = new Node(val, p, p->prev);
    p->prev = p->prev->next;
    ++siz;
}

void MyLinkedList::deleteAtIndex(int index)
{
    if (index < 0 || index >= siz)
        return;

    Node *p = head->next;
    for (int i = {0}; i != index; ++i)
        p = p->next;

    p->prev->next = p->next;
    p->next->prev = p->prev;

    delete p;
    --siz;
}

// solution ====================================================================

// singly linked list

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