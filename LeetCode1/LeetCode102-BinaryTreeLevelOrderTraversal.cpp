// LeetCode102-BinaryTreeLevelOrderTraversal.cpp
// Ad147
// Init: 19Mar03

/* -----------------------------------------------------------------------------

102. Binary Tree Level Order Traversal
Medium
Tree, Breadth-first Search

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:

Given binary tree [3,9,20,null,null,15,7],
----------------------------------------
    3
   / \
  9  20
    /  \
   15   7
----------------------------------------

return its level order traversal as:
----------------------------------------
[
  [3],
  [9,20],
  [15,7]
]
----------------------------------------

----------------------------------------------------------------------------- */

#include <deque>
#include <vector>
using std::deque;
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

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 13.7 MB, less than 89.44% of C++ online submissions for Binary Tree Level Order Traversal.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complextity: O(n).

class Solution
{
  public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
            return ret;

        deque<TreeNode *> queue{root};
        int nextLevelNodeNum = 1;
        while (!queue.empty())
        {
            vector<int> levelOutput;
            const int levelNodeNum = nextLevelNodeNum;
            nextLevelNodeNum = 0;
            for (int i = 0; i < levelNodeNum; ++i)
            {
                TreeNode *p = queue.front();
                queue.pop_front();
                levelOutput.push_back(p->val);
                if (p->left)
                {
                    queue.push_back(p->left);
                    ++nextLevelNodeNum;
                }
                if (p->right)
                {
                    queue.push_back(p->right);
                    ++nextLevelNodeNum;
                }
            }

            ret.push_back(std::move(levelOutput));
        }

        return ret;
    }
};
