// LeetCode094-BinaryTreeInorderTraversal.cpp
// Ad147
// Init: 19Feb28

/* -----------------------------------------------------------------------------

94. Binary Tree Inorder Traversal
Medium
Hash Table, Stack, Tree

Given a binary tree, return the inorder traversal of its nodes' values.

Example:
----------------------------------------
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
----------------------------------------

Follow up: Recursive solution is trivial, could you do it iteratively?

----------------------------------------------------------------------------- */

#include <vector>
using std::vector;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution-1 ==================================================================

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.2 MB, less than 62.34% of C++ online submissions for Binary Tree Inorder Traversal.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        vector<TreeNode *> stack{};
        TreeNode *p = root;
        while (!stack.empty() || p)
        {
            while (p)
            {
                stack.push_back(p);
                p = p->left;
            }

            p = stack.back();
            stack.pop_back();
            ret.push_back(p->val);

            p = p->right;
        }

        return ret;
    }
};

// Solution-0 ==================================================================

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 9.4 MB, less than 28.32% of C++ online submissions for Binary Tree Inorder Traversal.
// Algorithm: Recursion.
// Time Complexity: O(n): recursive function: T(n) = 2 * T(n / 2) + 1.
// Space Complexity: worst: O(n); average: O(log(n)).

class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        inorderTraversal(root, &ret);

        return ret;
    }

  private:
    void inorderTraversal(TreeNode *root, vector<int> *ret)
    {
        if (!root)
            return;
        inorderTraversal(root->left, ret);
        ret->push_back(root->val);
        inorderTraversal(root->right, ret);
    }
};
