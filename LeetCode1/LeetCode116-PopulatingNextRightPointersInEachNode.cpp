// LeetCode116-PopulatingNextRightPointersInEachNode.cpp
// Ad147
// Init: 19Mar19

/* -----------------------------------------------------------------------------

116. Populating Next Right Pointers in Each Node
Medium
Array, Tree, Depth-first Search

You are given a **perfect binary tree** where all leaves are on the same level, and every parent has two children.  
The binary tree has the following definition:
----------------------------------------
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
----------------------------------------

Populate each next pointer to point to its next right node. 
If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Example:
----------------------------------------
Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
---------------------------------------- 

Note:
- You may only use constant extra space.
- Recursive approach is fine, implicit stack space does not count as extra space for this problem.

----------------------------------------------------------------------------- */

// Definition for a Node.
class Node
{
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// Solution-0 ==================================================================

// Runtime: 60 ms, faster than 81.78% of C++ online submissions for Populating Next Right Pointers in Each Node.
// (The submissions of this problem seems to be mixed with some other problem whose runtimes are faster.)
// Memory Usage: 27.2 MB, less than 36.50% of C++ online submissions for Populating Next Right Pointers in Each Node.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        if (!root->left)
            return root;

        root->left->next = root->right;
        if (root->next)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
