// LeetCode021-MergeTwoSortedLists.cpp
// Ad
// Update: 19Mar14

/* -----------------------------------------------------------------------------

21. Merge Two Sorted Lists
Easy
Linked List

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
----------------------------------------
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
----------------------------------------

----------------------------------------------------------------------------- */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution ====================================================================

// Runtime: 12 ms, faster than 99.28% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 10.2 MB, less than 17.85% of C++ online submissions for Merge Two Sorted Lists.
// This solution is from yangliguang@LeetCode

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
