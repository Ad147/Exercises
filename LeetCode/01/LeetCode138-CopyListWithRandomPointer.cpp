// LeetCode138-CopyListWithRandomPointer.cpp
// Ad
// Init: 19Mar16

/* -----------------------------------------------------------------------------

138. Copy List with Random Pointer
Medium
Hash Table, Linked List

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep newNode of the list.

Example 1:
+----------+-----+----------+
|   1      |     |   2      |
|  next ---|---> |  next ---|---> NULL
| random --|---> | random --|---
+----------+-----+----------+  |
                      ^--------
----------------------------------------

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.
----------------------------------------

Note:
1. You must return the newNode of the given head as a reference to the cloned list.

----------------------------------------------------------------------------- */

#include <unordered_map>

// Definition for a Node.
struct Node
{
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};

// Solution-0 ==================================================================

// Runtime: 36 ms, faster than 100.00% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 22.2 MB, less than 5.21% of C++ online submissions for Copy List with Random Pointer.
// Algorithm: Iteration twice.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;

        Node *newHead = new Node;
        Node *oldNode = head, *newNode = newHead;
        std::unordered_map<Node *, Node *> mapOld2New;
        // First loop: Create nodes.
        while (oldNode)
        {
            newNode->next = new Node{oldNode->val, nullptr, nullptr};
            mapOld2New.insert({oldNode, newNode->next});
            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        oldNode = head;
        newNode = newHead->next;
        // Second loop: Deal random pointers.
        while (oldNode)
        {
            if (oldNode->random)
                newNode->random = mapOld2New.at(oldNode->random);

            oldNode = oldNode->next;
            newNode = newNode->next;
        }

        return newHead->next;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
