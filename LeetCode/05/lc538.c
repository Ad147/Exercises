/* lc538.c */

/* LeetCode 538. Convert BST to Greater Tree `E` */
/* 1sk | 100% | 11' */
/* A~0f24 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *convertBST(struct TreeNode *root)
{
    convert(root, 0);

    return root;
}

int convert(struct TreeNode *node, int sum)
{
    if (!node)
        return sum;

    node->val += convert(node->right, sum);
    sum = convert(node->left, node->val);

    return sum;
}
