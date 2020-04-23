/* lc111.c */

/* LeetCode 111. Minimum Depth of Binary Tree `E` */
/* acc | 65%* | 36' */
/* A~0d23 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode *root)
{
    if (!root)
        return 0;

    struct TreeNode *queue[100];
    for (int i = 0; i < 100; i++)
        queue[i] = NULL;
    int head = 0, tail = 0;
    queue[tail++] = root;
    tail++;

    int depth = 1;
    while (1)
    {
        struct TreeNode *node = queue[head];
        if (node == NULL)
        {
            depth++;
            head = head == 99 ? 0 : head + 1;
            continue;
        }

        if (!node->left && !node->right)
            return depth;

        if (node->left)
        {
            queue[tail] = node->left;
            tail = tail == 99 ? 0 : tail + 1;
        }
        if (node->right)
        {
            queue[tail] = node->right;
            tail = tail == 99 ? 0 : tail + 1;
        }
        if (queue[head + 1] == NULL)
            tail = tail == 99 ? 0 : tail + 1;

        head = head == 99 ? 0 : head + 1;
    }

    return depth;
}
