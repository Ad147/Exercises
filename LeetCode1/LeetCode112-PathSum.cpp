// LeetCode112-PathSum.cpp
// Ad
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// solution ====================================================================

// runtime: 4 ms, faster than 100.00%

class Solution
{
  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        if ((root->val == sum) && !(root->left) && !(root->right))
            return true;
        else if (!(root->left) && !(root->right))
            return false;
        else
            return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};
