// LeetCode145-BinaryTreePostorderTraversal.cpp
// Ad147
// Init: 19Mar01

/* -----------------------------------------------------------------------------

145. Binary Tree Postorder Traversal
Hard
Stack, Tree

Given a binary tree, return the postorder traversal of its nodes' values.

Example:
----------------------------------------
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
----------------------------------------

Follow up: Recursive solution is trivial, could you do it iteratively?

----------------------------------------------------------------------------- */

#include <vector>
#include <algorithm> // std::reverse
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

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.2 MB, less than 67.70% of C++ online submissions for Binary Tree Postorder Traversal.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        vector<TreeNode *> stack{root};
        while (!stack.empty())
        {
            TreeNode *p = stack.back();
            stack.pop_back();
            ret.push_back(p->val);

            if (p->left)
                stack.push_back(p->left);
            if (p->right)
                stack.push_back(p->right);
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};

// Solution-0 ==================================================================

// Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.4 MB, less than 18.41% of C++ online submissions for Binary Tree Postorder Traversal.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;

        postorderTraversal(root, &ret);

        return ret;
    }

  private:
    void postorderTraversal(TreeNode *root, vector<int> *ret)
    {
        if (!root)
            return;
        postorderTraversal(root->left, ret);
        postorderTraversal(root->right, ret);
        ret->push_back(root->val);
    }
};
