// LeetCode101-SymmetricTree.cpp
// Ad147
// Init: 19Mar05

/* -----------------------------------------------------------------------------

101. Symmetric Tree
Easy
Tree, Depth-first Search, Breadth-first Search

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
----------------------------------------
    1
   / \
  2   2
 / \ / \
3  4 4  3
----------------------------------------

But the following [1,2,2,null,3,null,3] is not:
----------------------------------------
    1
   / \
  2   2
   \   \
   3    3
----------------------------------------

Note:
Bonus points if you could solve it both recursively and iteratively.

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

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
// Memory Usage: 15.8 MB, less than 84.66% of C++ online submissions for Symmetric Tree.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        vector<TreeNode *> leftStack{root->left};
        vector<TreeNode *> rightStack{root->right};
        while (!leftStack.empty())
        {
            TreeNode *lp = leftStack.back();
            leftStack.pop_back();
            TreeNode *rp = rightStack.back();
            rightStack.pop_back();

            if (!lp && !rp)
                continue;
            if (!lp || !rp)
                return false;
            if (lp->val != rp->val)
                return false;

            leftStack.push_back(lp->right);
            leftStack.push_back(lp->left);
            rightStack.push_back(rp->left);
            rightStack.push_back(rp->right);
        }

        return true;
    }
};

// Solution-0 ==================================================================

// Runtime: 12 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16 MB, less than 28.70% of C++ online submissions for Symmetric Tree.
// Algorithm: Recursion.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;

        return isSymmetric(root->left, root->right);
    }

  private:
    bool isSymmetric(TreeNode *t1, TreeNode *t2)
    {
        if (!t1 && !t2)
            return true;
        if (!t1 || !t2)
            return false;
        if (t1->val != t2->val)
            return false;

        return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
    }
};
