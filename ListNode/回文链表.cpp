#include "commen.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
};