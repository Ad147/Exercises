// LeetCode160-IntersectionOfTwoLinkedLists.cpp
// Ad
// Write a program to find the node at which the intersection of two singly linked lists begins.
// Notes:
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        if (headA == headB)
            return headA;

        ListNode *pA = {headA}, *pB = {headB};
        ListNode *tailA = {nullptr}, *tailB = {nullptr};
        while (pA != pB)
        {
            if (pA->next != nullptr)
                pA = pA->next;
            else
            {
                tailA = pA;
                pA = headB;
            }

            if (pB->next != nullptr)
                pB = pB->next;
            else
            {
                tailB = pB;
                pB = headA;
            }

            if (tailA != tailB && tailA != nullptr && tailB != nullptr)
                return nullptr;
        }

        return pA;
    }
};
