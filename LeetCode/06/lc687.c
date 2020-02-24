/* lc687.c */

/* LeetCode 687 Longest Univalue Path `E` */
/* A~0b22 */
/* acc | 75' | rt100% | mu100% */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static int maxlen;

int longestUnivaluePath(struct TreeNode *root)
{
    maxlen = 0;
    longestLen(root);
    return maxlen;
}

int longestLen(struct TreeNode *root)
{
    if (!root)
        return 0;

    int llen = longestLen(root->left);
    int rlen = longestLen(root->right);
    llen = (root->left && (root->val == root->left->val)) ? llen + 1 : 0;
    rlen = (root->right && (root->val == root->right->val)) ? rlen + 1 : 0;

    maxlen = maxlen > (llen + rlen) ? maxlen : (llen + rlen);
    return (llen > rlen) ? llen : rlen;
}
