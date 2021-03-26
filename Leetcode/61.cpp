/**
 * 61. 旋转链表
 * link：https://leetcode-cn.com/problems/rotate-list/
 */

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0 || head == nullptr || head->next == nullptr)
        {
            return head;
        }

        int n = 1;
        ListNode *tmp = head;
        while (n <= k && tmp->next != nullptr)
        {
            tmp = tmp->next;
            ++n;
        }

        if (n < k) // the size of list < rotate size
        {
            tmp = head;
            k %= n;
            while (k-- > 0)
                tmp = tmp->next;
        }
        else if (n == k) // the size of list = rotate size
            return head;

        ListNode *begin = head;      // begin is the node whose next = future head
        while (tmp->next != nullptr) // tmp is the last node
        {
            tmp = tmp->next;
            begin = begin->next;
        }

        tmp->next = head;
        tmp = begin->next;
        begin->next = nullptr;
        return tmp;
    }
};