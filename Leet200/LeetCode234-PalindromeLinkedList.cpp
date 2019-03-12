// LeetCode234-PalindromeLinkedList.cpp
// Ad147
// Init: 19Mar11

/* -----------------------------------------------------------------------------

234. Palindrome Linked List
Easy
Linked List, Two Pointers

Given a singly linked list, determine if it is a palindrome.

Example 1:
----------------------------------------
Input: 1->2
Output: false
----------------------------------------

Example 2:
----------------------------------------
Input: 1->2->2->1
Output: true
----------------------------------------

Follow up:
Could you do it in O(n) time and O(1) space?

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

// Runtime: 16 ms, faster than 99.74% of C++ online submissions for Palindrome Linked List.
// Memory Usage: 12.5 MB, less than 80.96% of C++ online submissions for Palindrome Linked List.
// Algorithm: Reverse half, two pointers.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        // Reverse the first half
        ListNode *p = head;
        while (p->next && p->next->next)
        {
            if ((p->next->val == head->val) || (p->next->next->val == head->val))
                break;

            auto tmp = head;
            head = p->next;
            p->next = head->next;
            head->next = tmp;
        }

        const ListNode *mid = p->next;
        p = p->next;
        if (p->next && p->next->val == head->val)
            p = p->next;
        while (p && head != mid)
        {
            if (p->val != head->val)
                return false;
            p = p->next;
            head = head->next;
            if (!p && head == mid)
                return true;
        }

        return false;
    }
};

static const auto ___ = []() { std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
