// LeetCode236-LowestCommonAncestorOfABinaryTree.cpp
// Ad147
// Init: 19Mar21
/* -----------------------------------------------------------------------------

236. Lowest Common Ancestor of a Binary Tree
Medium
Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
----------------------------------------
     3
   /   \
  5     1
 / \   / \
6   2 0   8
   / \
  7   4
----------------------------------------

Example 1:
----------------------------------------
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
----------------------------------------

Example 2:
----------------------------------------
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
----------------------------------------

Note:
- All of the nodes' values will be unique.
- p and q are different and both values will exist in the binary tree.

----------------------------------------------------------------------------- */

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

// Solution-0 ==================================================================

// Runtime: 16 ms, faster than 99.97% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 16.8 MB, less than 41.40% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    Solution() : ans{nullptr} {}

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        recurse(root, p, q);
        return ans;
    }

  private:
    TreeNode *ans;

    bool recurse(TreeNode *t, TreeNode *p, TreeNode *q)
    {
        if (!t)
            return false;

        int mid = (t == p || t == q) ? 1 : 0;
        int left = recurse(t->left, p, q) ? 1 : 0;
        int right = recurse(t->right, p, q) ? 1 : 0;

        if (mid + left + right > 1)
            ans = t;

        return (mid + left + right > 0);
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
