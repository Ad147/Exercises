// lc257.cpp

// LeetCode 257. Binary Tree Paths `E`
// 1sk | 79%* | 21'
// A~0e17

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    vector<string> paths;

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return paths;

        trackNode(root, to_string(root->val));

        return paths;
    }

private:
    void trackNode(TreeNode *node, string path)
    {
        if (!node->left && !node->right)
            paths.push_back(path);
        else
        {
            if (node->left)
                trackNode(node->left, path + "->" + to_string(node->left->val));
            if (node->right)
                trackNode(node->right, path + "->" + to_string(node->right->val));
        }
    }
};
