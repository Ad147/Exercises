// LeetCode002-AddTwoNumbers.cpp
// Ad
// Update: 19Mar14

/* -----------------------------------------------------------------------------

2. Add Two Numbers
Medium
Linked List, Math

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
----------------------------------------
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solution-0 ==================================================================

// Runtime: 36 ms, faster than 99.17% of C++ online submissions for Add Two Numbers.
// Memory Usage: 18.8 MB, less than 90.86% of C++ online submissions for Add Two Numbers.
// Algorithm: Recursion.
// Time Complexity: O(max(m, n)).
// Space Complexity: O(1).

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addTwoNumbers(l1, l2, 0);
    }

  private:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry)
    {
        if (!l1 && !l2)
        {
            if (carry)
                return new ListNode{carry};
            else
                return nullptr;
        }

        ListNode *ret = l1;
        int l1Val = 0, l2Val = 0;
        if (l1)
        {
            l1Val = l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            ret = l2;
            l2Val = l2->val;
            l2 = l2->next;
        }

        ret->val = l1Val + l2Val + carry;
        carry = ret->val / 10;
        ret->val %= 10;

        ret->next = addTwoNumbers(l1, l2, carry);

        return ret;
    }
};

// Old Solution ================================================================

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
