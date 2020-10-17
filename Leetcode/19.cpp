/**
 * 19. 删除链表的倒数第N个节点
 * link：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 */

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *res = new ListNode(-1, head);
        ListNode *cur = res;
        head = cur;

        while (n-- > 0)
            cur = cur->next;

        while (cur->next != nullptr)
        {
            head = head->next;
            cur = cur->next;
        }

        head->next = head->next->next;
        
        cur = res;
        res = res->next;
        delete cur;

        return res;
    }
};