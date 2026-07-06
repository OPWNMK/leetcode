#include "commen.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *pre = slow;
        while (slow != fast)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            if(fast == fast->next)
                return fast;
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }
};