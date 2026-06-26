#include "commen.h"

class Solution
{
public:
    /**
     *  @brief 计算长度
     */
    int countList(ListNode *head)
    {
        ListNode *h = head;
        int length = 0;
        while (h != nullptr)
        {
            h = h->next;
            length++;
        }
        return length;
    }
    /**
     * @brief   给你两个单链表的头节点 headA 和 headB
     *          请你找出并返回两个单链表相交的起始节点。
     *          如果两个链表不存在相交节点，返回 null 。
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int lenA = countList(headA);
        int lenB = countList(headB);

        ListNode *tempA = headA;
        ListNode *tempB = headB;

        // 移动较长链表，使两者对齐
        int diff = abs(lenA - lenB);
        if (lenA > lenB)
        {
            for (int i = 0; i < diff; ++i)
                tempA = tempA->next;
        }
        else
        {
            for (int i = 0; i < diff; ++i)
                tempB = tempB->next;
        }
        while (tempA && tempB)
        {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};