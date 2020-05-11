/* lc226.c */

/* LeetCode 226. Invert Binary Tree `E` */
/* 1sk | 100% | 6' */
/* A~0e11 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *invertTree(struct TreeNode *root)
{
    if (!root)
        return NULL;

    invertTree(root->left);
    invertTree(root->right);

    struct TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    return root;
}
