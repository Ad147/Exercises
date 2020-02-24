// LeetCode104-MaximumDepthOfBinaryTree.cpp
// Ad147
// Init: 19Mar04

/* -----------------------------------------------------------------------------

104. Maximum Depth of Binary Tree
Easy
Tree, Depth-first Search

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:
----------------------------------------
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
----------------------------------------

return its depth = 3.

----------------------------------------------------------------------------- */

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

// Solution-0 ==================================================================

// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19 MB, less than 96.79% of C++ online submissions for Maximum Depth of Binary Tree.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
};
