// LeetCode328-OddEvenLinkedList.cpp
// Ad147
// Init: 19Mar10

/* -----------------------------------------------------------------------------

328. Odd Even Linked List
Medium
Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. 
The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
----------------------------------------
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
----------------------------------------

Example 2:
----------------------------------------
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
----------------------------------------

Note:
- The relative order inside both the even and odd groups should remain as it was in the input.
- The first node is considered odd, the second node even and so on ...

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

// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 9.8 MB, less than 93.88% of C++ online submissions for Odd Even Linked List.
// Algorithm: Iteration.
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *evenHead = head->next;
        ListNode *oddPrev = head, *evenPrev = evenHead;
        ListNode *curr = evenHead->next;
        bool isOdd = true;
        while (curr)
        {
            if (isOdd)
                oddPrev = oddPrev->next = curr;
            else
                evenPrev = evenPrev->next = curr;
            curr = curr->next;
            isOdd = !isOdd;
        }
        oddPrev->next = evenHead;
        evenPrev->next = nullptr;

        return head;
    }
};

static const auto ___ = []() { std::cout.sync_with_stdio(false);cin.tie(0);return 0; }();
