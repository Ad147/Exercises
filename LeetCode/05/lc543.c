/* lc543.c */

/* LeetCode 543. Diameter of Binary Tree `E` */
/* acc | 96% | 15' */
/* A~0f26 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int maxlen;

int diameterOfBinaryTree(struct TreeNode *root)
{
    if (!root)
        return 0;

    maxlen = 0;
    getDiameter(root);

    return maxlen;
}

int getDiameter(struct TreeNode *node)
{
    if (!node)
        return 0;

    int leftlen = getDiameter(node->left);
    int rightlen = getDiameter(node->right);
    if (leftlen + rightlen > maxlen)
        maxlen = leftlen + rightlen;

    return leftlen > rightlen ? leftlen + 1 : rightlen + 1;
}
