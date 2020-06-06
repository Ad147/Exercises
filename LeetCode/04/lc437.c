/* lc437.c */

/* LeetCode 437. Path Sum III `E` */
/* acc | 97% | 54' */
/* A~0f06 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countPathSum(struct TreeNode *node, int expect, int *path, int len);

int pathSum(struct TreeNode *root, int sum)
{
    int path[1000];

    return countPathSum(root, sum, path, 0);
}

int countPathSum(struct TreeNode *node, int expect, int *path, int len)
{
    if (!node)
        return 0;

    path[len] = node->val;
    int sum = 0;
    int cnt = 0;
    for (int i = len; i >= 0; i--)
    {
        sum += path[i];
        if (sum == expect)
            cnt++;
    }

    return cnt +
           countPathSum(node->left, expect, path, len + 1) +
           countPathSum(node->right, expect, path, len + 1);
}
