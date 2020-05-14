/* lc235.c */

/* LeetCode 235. Lowest Common Ancestor of a Binary Search Tree `E` */
/* 1sk | 96% | 9' */
/* A~0e14 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}
