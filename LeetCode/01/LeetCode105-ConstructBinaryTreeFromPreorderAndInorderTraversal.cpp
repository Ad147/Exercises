// LeetCode105-ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
// Ad147
// Init: 19Mar18

/* -----------------------------------------------------------------------------

105. Construct Binary Tree from Preorder and Inorder Traversal
Medium
Array, Tree, Depth-first Search

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
----------------------------------------
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
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

// Runtime: 20 ms, faster than 91.21% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 20.9 MB, less than 7.27% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
    using Itr = vector<int>::const_iterator;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }

  private:
    TreeNode *buildTree(Itr preLow, Itr preHigh, Itr inLow, Itr inHigh)
    {
        if (preLow == preHigh || inLow == inHigh)
            return nullptr;

        TreeNode *newNode = new TreeNode{*preLow};

        Itr inMid = std::find(inLow, inHigh, newNode->val);
        newNode->left = buildTree(preLow + 1, preLow + (inMid - inLow) + 1, inLow, inMid);
        newNode->right = buildTree(preLow + (inMid - inLow) + 1, preHigh, inMid + 1, inHigh);

        return newNode;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
