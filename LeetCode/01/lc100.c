/* lc100.c */

/* LeetCode 100. Same Tree `E` */
/* 1sk | 21%* | 8' */
/* A~0d12 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
