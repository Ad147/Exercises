// LeetCode141-LinkedListCycle.cpp
// Ad
// Given a linked list, determine if it has a cycle in it.
// Two-pointer technique.

#include <iostream>

// solution ====================================================================

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;

        ListNode *fp = {head->next}, *sp = head;
        while (true)
        {
            for (int i = {0}; i < 2; ++i)
            {
                if (fp == nullptr)
                    return false;
                else if (fp == sp)
                    return true;
                fp = fp->next;
            }
            sp = sp->next;
        }
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;

    system("pause");
    return 0;
}
