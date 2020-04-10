/* lc83.c */

/* LeetCode 83. Remove Duplicates from Sorted List `E` */
/* acc | 94% | 17' */
/* A~0d10 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    if (!head)
        return NULL;

    struct ListNode *left, *right;
    left = right = head;
    while (right->next)
    {
        right = right->next;
        if (right->val != left->val)
        {
            left->next = right;
            left = right;
        }
    }
    if (left->val == right->val)
        left->next = NULL;

    return head;
}
