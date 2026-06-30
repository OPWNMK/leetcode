#include "commen.h"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // unordered_set<ListNode*> sets;
        // ListNode* l = head;
        // while(l)
        // {
        //     if(sets.count(l))
        //     {
        //         return true;
        //     }
        //     sets.insert(l);
        //     l = l->next;
        // }
        // return false;
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};