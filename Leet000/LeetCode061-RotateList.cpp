// LeetCode061-RotateList.cpp
// Ad
// Init: 19Mar17

/* -----------------------------------------------------------------------------

61. Rotate List
Medium
Linked List, Two Pointers

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
----------------------------------------
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
----------------------------------------

Example 2:
----------------------------------------
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
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

// Runtime: 12 ms, faster than 99.42% of C++ online submissions for Rotate List.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Rotate List.
// Algorithm: Iteration twice.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;

        int num = 1;
        auto tail = head;
        for (; tail->next; tail = tail->next)
            ++num;
        tail->next = head;

        k = k % num;
        auto newTail = head;
        for (int i = 0; i < num - k - 1; ++i)
            newTail = newTail->next;
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
