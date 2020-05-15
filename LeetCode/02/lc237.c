/* lc237.c */

/* LeetCode 237. Delete Node in a Linked List `E` */
/* 1sk | 94% | 10' */
/* A~0e15 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void deleteNode(struct ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}
