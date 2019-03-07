// LeetCode106-ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
// Ad147
// Init: 19Mar07

/* -----------------------------------------------------------------------------

106. Construct Binary Tree from Inorder and Postorder Traversal
Medium
Array, Tree, Depth-first Search

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
----------------------------------------
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
----------------------------------------

Return the following binary tree:
----------------------------------------
    3
   / \
  9  20
    /  \
   15   7
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
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

// Solution-0 ==================================================================

// Runtime: 16 ms, faster than 99.51% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
// Memory Usage: 20.9 MB, less than 16.15% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
    using Index = vector<int>::const_iterator;

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildTree(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }

  private:
    TreeNode *buildTree(Index inLeft, Index inRight, Index postLeft, Index postRight)
    {
        if (inLeft == inRight || postLeft == postRight)
            return nullptr;

        TreeNode *root = new TreeNode(*(postRight - 1));

        // Index inRoot = std::find(inLeft, inRight, root->val);
        // For the cases in this problem, searching reversely seems to be faster.
        Index inRoot;
        for (inRoot = inRight - 1; inRoot != inLeft; --inRoot)
            if (*inRoot == root->val)
                break;
        root->left = buildTree(inLeft, inRoot, postLeft, postLeft + (inRoot - inLeft));
        root->right = buildTree(inRoot + 1, inRight, postLeft + (inRoot - inLeft), postRight - 1);

        return root;
    }
};
