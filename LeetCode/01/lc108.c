/* lc108.c */

/* LeetCode 108. Convert Sorted Array to Binary Search Tree `E` */
/* 1sk | 99% | 10' */
/* A~0d21 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *buildTree(int *nums, int i, int j);

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    struct TreeNode *root = buildTree(nums, 0, numsSize);

    return root;
}

struct TreeNode *buildTree(int *nums, int i, int j)
{
    if (i >= j)
        return NULL;

    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    int mid = (i + j) / 2;
    node->val = nums[mid];
    node->left = buildTree(nums, i, mid);
    node->right = buildTree(nums, mid + 1, j);

    return node;
}
