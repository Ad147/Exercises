// lc501.cpp

// LeetCode 501. Find Mode in Binary Search Tree `E`
// acc | 99% | 26'
// A~0f17

static auto x = []() {ios_base::sync_with_stdio(false);cin.tie(NULL);return NULL; }();

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
    vector<int> res;
    int maxCnt = 1;
    int currCnt = 1;
    int prevVal = -1;

public:
    vector<int> findMode(TreeNode *root)
    {
        traverse(root);

        return res;
    }

private:
    void traverse(TreeNode *node)
    {
        if (!node)
            return;

        traverse(node->left);

        currCnt = node->val == prevVal ? currCnt + 1 : 1;
        if (currCnt == maxCnt)
            res.push_back(node->val);
        else if (currCnt > maxCnt)
        {
            res = {node->val};
            maxCnt = currCnt;
        }

        prevVal = node->val;

        traverse(node->right);
    }
};
