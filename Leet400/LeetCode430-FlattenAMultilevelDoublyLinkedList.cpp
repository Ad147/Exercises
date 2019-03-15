// LeetCode430-FlattenAMultilevelDoublyLinkedList.cpp
// Ad
// Init: 19Mar15

/* -----------------------------------------------------------------------------

430. Flatten a Multilevel Doubly Linked List
Medium
Linked List, Depth-first Search

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. 
You are given the head of the first level of the list.

Example:
----------------------------------------
Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
----------------------------------------

----------------------------------------------------------------------------- */

// Definition for a Node.
struct Node
{
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child)
    {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

// Solution-0 =================================================================j

// Runtime: 96 ms, faster than 100.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 31.3 MB, less than 5.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;

        Node *p = head;
        helper(p);

        return head;
    }

  private:
    void helper(Node *&p)
    {
        if (!p->child && !p->next)
            return;

        Node *n = p->next;
        if (p->child)
        {
            p->child->prev = p;
            p->next = p->child;
            p->child = nullptr;
            p = p->next;
            helper(p);
            if (n)
            {
                n->prev = p;
                p->next = n;
            }
        }
        if (p->next)
        {
            p = p->next;
            helper(p);
        }
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
