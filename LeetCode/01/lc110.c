/* lc110.c */

/* LeetCode 110. Balanced Binary Tree `E` */
/* 1sk | 97% | 26' */
/* A~0d22 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isBalanced(struct TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return 1;

    int lh = -1, rh = -1;
    if (root->left)
    {
        lh = isBalanced(root->left);
        if (lh == 0)
            return 0;
    }
    if (root->right)
    {
        rh = isBalanced(root->right);
        if (rh == 0)
            return 0;
    }

    lh = (lh == -1) ? 0 : lh;
    rh = (rh == -1) ? 0 : rh;
    if (abs(lh - rh) > 1)
        return 0;
    else
        return lh > rh ? lh + 1 : rh + 1;
}
