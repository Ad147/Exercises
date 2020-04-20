// lc107.cpp

// LeetCode 107. Binary Tree Level Order Traversal II `E`
// 1sk | 95% | 30'
// A~0d20

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret;

        levelTraversal(root, ret, 0);

        for (int i = 0, j = ret.size() - 1; i < j; i++, j--)
            swap(ret[i], ret[j]);

        return ret;
    }

private:
    void levelTraversal(TreeNode *node, vector<vector<int>> &ivv, int level)
    {
        if (!node)
            return;

        if (ivv.size() <= level)
            ivv.push_back(vector<int>{node->val});
        else
            ivv[level].push_back(node->val);

        levelTraversal(node->left, ivv, level + 1);
        levelTraversal(node->right, ivv, level + 1);
    }
};
