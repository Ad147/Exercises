/* lc530.c */

/* LeetCode 530. Minimum Absolute Difference in BST `E` */
/* acc | 90% | 29' */
/* A~0f23 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findMaxVal(struct TreeNode *node);
int findMinVal(struct TreeNode *node);

int getMinimumDifference(struct TreeNode *root)
{
    if (!root)
        return INT_MAX;

    int minDiff;
    int leftMax = findMaxVal(root->left);
    int rightMin = findMinVal(root->right);
    if (leftMax < 0 && rightMin < 0)
        return INT_MAX;
    else if (leftMax < 0)
        minDiff = rightMin - root->val;
    else if (rightMin < 0)
        minDiff = root->val - leftMax;
    else
        minDiff = (rightMin - root->val < root->val - leftMax) ? rightMin - root->val : root->val - leftMax;

    int diffL = getMinimumDifference(root->left);
    minDiff = minDiff < diffL ? minDiff : diffL;
    int diffR = getMinimumDifference(root->right);
    minDiff = minDiff < diffR ? minDiff : diffR;

    return minDiff;
}

int findMaxVal(struct TreeNode *node)
{
    if (!node)
        return -1;

    if (!node->right)
        return node->val;
    else
        return findMaxVal(node->right);
}

int findMinVal(struct TreeNode *node)
{
    if (!node)
        return -1;

    if (!node->left)
        return node->val;
    else
        return findMinVal(node->left);
}
