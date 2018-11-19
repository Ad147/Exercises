// LeetCode021-MergeTwoSortedLists.cpp
// Ad
// Merge two sorted linked list and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solution ====================================================================

// solution from yangliguang @LeetCode
// runtime: 8 ms, faster than 89.04%

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

// -----------------------------------------------------------------------------

// runtime: 16 ms, faster than 12.06%

class Solution1
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *head, *p, *p1 = l1, *p2 = l2;
        if (p1->val < p2->val)
        {
            head = p = p1;
            p1 = p1->next;
        }
        else
        {
            head = p = p2;
            p2 = p2->next;
        }

        while (p1 != nullptr || p2 != nullptr)
        {
            if (p2 == nullptr)
                link(p, p1);
            else if (p1 == nullptr)
                link(p, p2);
            else if (p1->val < p2->val)
                link(p, p1);
            else
                link(p, p2);
        }

        return head;
    }

  private:
    void link(ListNode *&p, ListNode *&pn)
    {
        p->next = pn;
        p = p->next;
        pn = pn->next;
    }
};
