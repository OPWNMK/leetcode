#include "commen.h"



class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *node = head;
        ListNode *pre = nullptr;
        while (node != nullptr)
        {
            ListNode *temp = node->next;
            node->next = pre;
            pre = node;
            node = temp;
        }
        return pre;
    }
    int countLength(ListNode *head)
    {
        int length = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            node = node->next;
            length++;
        }
        return length;
    }
    ListNode *findMid(ListNode *head, int length)
    {
        ListNode *node = head;
        for (int i = 0; i < length / 2; i++)
        {
            node = node->next;
        }
        if (length % 2 != 0)
            node = node->next;
        return node;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *node1 = head;
        bool ans = false;
        int length = countLength(head);
        if (length == 1)
            return true;
        ListNode *node2 = findMid(head, length);
        node1 = head;
        node2 = reverseList(node2);
        while (node2 != nullptr)
        {
            if (node1->val != node2->val)
            {
                ans = false;
                break;
            }
            ans = true;
            node1 = node1->next;
            node2 = node2->next;
        }
        return ans;
    }

    ListNode *findMidwithFSpoint(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    bool isPalindrome2(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }
        ListNode *node = head;
        ListNode *midNode = findMidwithFSpoint(head);
        midNode = reverseList(midNode->next);
        bool ans = true;
        while (midNode != nullptr && ans)
        {
            if (node->val != midNode->val)
            {
                ans = false;
            }
            node = node->next;
            midNode = midNode->next;
        }
        return ans;
    }
};