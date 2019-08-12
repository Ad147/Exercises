// LeetCode019-RemoveNthNodeFromEndOfList.cpp
// Ad
// Given a linked list, remove the n-th node from the end of list and return its head.
// Note:
// Given n will always be valid.

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// solution ====================================================================

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return nullptr;

        int sz = {0};
        ListNode *p = {head};
        while (p != nullptr)
        {
            p = p->next;
            ++sz;
        }

        if (sz == n)
        {
            p = head->next;
            delete head;
            return p;
        }

        p = head;
        for (int i = {0}; i < (sz - n - 1); ++i)
        {
            p = p->next;
        }

        ListNode *temp = p->next;
        p->next = temp->next;
        delete temp;

        return head;
    }
};
