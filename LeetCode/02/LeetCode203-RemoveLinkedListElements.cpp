// LeetCode203-RemoveLinkedListElements.cpp
// Ad147
// Init: 19Mar09

/* -----------------------------------------------------------------------------

203. Remove Linked List Elements
Easy
Linked List

Remove all elements from a linked list of integers that have value val.

Example:
----------------------------------------
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
----------------------------------------

----------------------------------------------------------------------------- */

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution-0 ==================================================================

// Runtime: 28 ms, faster than 99.92% of C++ online submissions for Remove Linked List Elements.
// Memory Usage: 11.6 MB, less than 10.55% of C++ online submissions for Remove Linked List Elements.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        ListNode watcher(-65536);
        watcher.next = head;
        ListNode *prev = &watcher;
        ListNode *curr = prev->next;
        while (curr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }

        return watcher.next;
    }
};
