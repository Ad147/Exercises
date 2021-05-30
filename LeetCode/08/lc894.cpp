// LeetCode 894. All Possible Full Binary Trees `M`
// acc | 72% | 51'
// A~1o30

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
    map<int, vector<TreeNode *>> dic;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (dic.find(n) == dic.end())
        {
            vector<TreeNode *> ans = vector<TreeNode *>();
            if (n == 1)
                ans.push_back(new TreeNode(0));
            else if (n % 2 == 1)
            {
                for (int x = 0; x < n; x++)
                {
                    int y = n - 1 - x;
                    for (auto left : allPossibleFBT(x))
                        for (auto right : allPossibleFBT(y))
                        {
                            TreeNode *node = new TreeNode(0);
                            node->left = left;
                            node->right = right;
                            ans.push_back(node);
                        }
                }
            }
            dic[n] = ans;
        }
        return dic[n];
    }
};