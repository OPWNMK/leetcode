#include "commen.h"



class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int A_length = 0;
        int B_length = 0;
        bool mvA = false,mvB = false;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA != nullptr)
        {
            tempA = tempA->next;
            A_length++;
        }
        while(tempB != nullptr)
        {
            tempB = tempB->next;
            B_length++;
        }
        tempA = headA;
        tempB = headB;
        if(A_length > B_length)
            mvA = true;
        else
            mvB = true;
        if(mvA)
        {
            for(int i = 0;i < abs(A_length - B_length);i++)
                tempA = tempA->next;;
        }
        if(mvB)
        {
            for(int i = 0;i < abs(A_length - B_length);i++)
            {
                tempB = tempB->next;
            }
        }
        ListNode* ans = nullptr;
        while(tempA != nullptr && tempB != nullptr)
        {
            if(tempA == tempB)
            {
                ans = tempA;
                break;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return ans;
    }
};