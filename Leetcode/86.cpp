/**
 * 86. 分隔链表
 * link：https://leetcode-cn.com/problems/partition-list/
 */

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = new ListNode(-1);
        ListNode *greater = new ListNode(-1);
        ListNode *tmp = greater, *tmp1 = less;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        less->next = tmp->next;

        return tmp1->next;
    }
};