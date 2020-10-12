/**
 * 24. 两两交换链表中的节点
 * link：https://leetcode-cn.com/problems/swap-nodes-in-pairs/
 */

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *res = head->next;

        head->next = swapPairs(head->next->next);
        res->next = head;

        return res;
    }
};