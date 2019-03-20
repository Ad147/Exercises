// LeetCode117-PopulatingNextRightPointersInEachNodeII.cpp
// Ad147
// Init: 19Mar20
/* -----------------------------------------------------------------------------

117. Populating Next Right Pointers in Each Node II
Medium
Tree, Depth-first Search

Given a binary tree:
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
Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
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

// Runtime: 384 ms, faster than 83.59% of C++ online submissions for Populating Next Right Pointers in Each Node II.
// (The submissions of this problem seems to be mixed with some other problem whose runtimes are much faster.)
// Memory Usage: 66.8 MB, less than 43.69% of C++ online submissions for Populating Next Right Pointers in Each Node II.
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

        if (root->left)
            if (root->right)
                root->left->next = root->right;
            else
                root->left->next = findNextForChild(root);
        if (root->right)
            root->right->next = findNextForChild(root);

        connect(root->right);
        connect(root->left);

        return root;
    }

  private:
    Node *findNextForChild(Node *t)
    {
        if (!t || !t->next)
            return nullptr;

        if (t->next->left)
            return t->next->left;
        else if (t->next->right)
            return t->next->right;
        else
            return findNextForChild(t->next);
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
