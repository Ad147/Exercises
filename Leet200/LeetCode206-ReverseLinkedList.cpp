// LeetCode206-ReverseLinkedList.cpp
// Ad147
// Init: 19Mar08

/* -----------------------------------------------------------------------------

206. Reverse Linked List
Easy
Linked List

Reverse a singly linked list.

Example:
----------------------------------------
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
----------------------------------------

Follow up:
A linked list can be reversed either iteratively or recursively. Could you implement both?

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

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.3 MB, less than 25.03% of C++ online submissions for Reverse Linked List.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *p = head;
        while (p->next)
        {
            auto tmp = head;
            head = p->next;
            p->next = head->next;
            head->next = tmp;
        }

        return head;
    }
};
