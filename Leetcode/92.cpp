/**
 * 92. 反转链表 II
 * link：https://leetcode-cn.com/problems/reverse-linked-list-ii/
 */

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *tmp = new ListNode(-1, head);

        ListNode *last = tmp;           // the last node of non-reverse region
        for (int i = 1; i < left; ++i)
            last = last->next;

        // reverse region
        ListNode *prev = nullptr;
        ListNode *cur = last->next;
        ListNode *next;
        for (int i = 0; i <= right - left; ++i)
        {
            next = cur->next;

            cur->next = prev;
            
            prev = cur;
            cur = next;
        }

        // here
        // last->next is the last node of reverse region
        // prev is the first node of reverse region
        // cur is the first node of non-reverse region
        last->next->next = cur;
        last->next = prev;

        return tmp->next;
    }
};