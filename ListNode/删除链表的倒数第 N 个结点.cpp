#include "commen.h"

class Solution
{
public:
    /**
     * 给你一个链表，删除链表的倒数第 n 个结点
     * 并且返回链表的头结点
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *fast = head;
        ListNode *slow = dummy;
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};