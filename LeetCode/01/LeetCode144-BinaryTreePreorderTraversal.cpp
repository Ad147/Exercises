// LeetCode144-BinaryTreePreorderTraversal.cpp
// Ad147
// Init: 19Feb27

/* -----------------------------------------------------------------------------

144. Binary Tree Preorder Traversal
Medium
Stack, Tree

Given a binary tree, return the preorder traversal of its nodes' values.

Example:
----------------------------------------
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
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

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
// Memory Usage: 9 MB, less than 98.18% of C++ online submissions for Binary Tree Preorder Traversal.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        vector<TreeNode *> stack{root};
        while (!stack.empty())
        {
            TreeNode *p = stack.back();
            ret.push_back(p->val);
            stack.pop_back();
            if (p->right)
                stack.push_back(p->right);
            if (p->left)
                stack.push_back(p->left);
        }

        return ret;
    }
};

// Solution-0 ==================================================================

// Runtime: 4 ms.
// Memory Usage: 9.5 MB.
// Algorithm: Recursion.

class Solution
{
  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        preorderTraversal(root, &ret);

        return ret;
    }

  private:
    void preorderTraversal(TreeNode *root, vector<int> *ret)
    {
        if (!root)
            return;
        ret->push_back(root->val);
        preorderTraversal(root->left, ret);
        preorderTraversal(root->right, ret);
    }
};
