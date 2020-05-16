/**
 * 206. 反转链表    递归
 * link：https://leetcode-cn.com/problems/reverse-linked-list/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        return reverse(head);
    }

    ListNode *reverse(ListNode *head)
    {
        if (head->next == nullptr)
            return head;

        ListNode *res = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return res;
    }
};