// LeetCode142-LinkedListCycleII.cpp
// Ad
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// Two-pointer technique.

#include <iostream>
#include <set>

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
    ListNode *detectCycle(ListNode *head)
    {
        std::set<ListNode *> ns;
        ListNode *p = {head};
        while (p != nullptr)
        {
            if (ns.find(p) == ns.end())
                ns.insert(p);
            else
                return p;

            p = p->next;
        }
        return nullptr;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;

    system("pause");
    return 0;
}
