// LeetCode002_AddTwoNumbers.cpp
// Ad
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include <iostream>

// solution ====================================================================

// 32 ms
// --> to reach 28 ms (36%)

// Definition for singly-linked list (LeetCode)
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ret = new ListNode(0);
        auto p1 = l1, p2 = l2, pr = ret;
        bool car = {false};
        while (true)
        {
            if (car)
                pr->val = p1->val + p2->val + 1;
            else
                pr->val = p1->val + p2->val;

            if (pr->val >= 10)
            {
                pr->val %= 10;
                car = true;
            }
            else
                car = false;

            if ((p1->next == nullptr) || (p2->next == nullptr))
                break;
            p1 = p1->next;
            p2 = p2->next;
            pr->next = new ListNode(0);
            pr = pr->next;
        }

        if ((p1->next == nullptr) && (p2->next == nullptr))
            ;
        else
        {
            if (p1->next == nullptr)
                ;
            if (p2->next == nullptr)
                p2 = p1;

            while (true)
            {
                p2 = p2->next;
                pr->next = new ListNode(0);
                pr = pr->next;

                if (car)
                    pr->val = p2->val + 1;
                else
                    pr->val = p2->val;

                if (pr->val >= 10)
                {
                    pr->val %= 10;
                    car = true;
                }
                else
                    car = false;

                if (p2->next == nullptr)
                    break;
            }
        }

        if (car)
            pr->next = new ListNode(1);

        return ret;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    // 1st number: 923
    ListNode *l1 = new ListNode(3);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(9);
    // 2nd number: 89
    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(8);
    // result: 1012
    auto res = sol.addTwoNumbers(l1, l2);
    std::cout << res->val << res->next->val << res->next->next->val << res->next->next->next->val << std::endl;

    system("pause");
    return 0;
}
