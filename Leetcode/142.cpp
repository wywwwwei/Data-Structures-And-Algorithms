/**
 * 142. 环形链表 II     快慢指针
 * link：https://leetcode-cn.com/problems/linked-list-cycle-ii/
 */

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;

            if (fast == slow)
            {
                ListNode *tmp = head;
                while (tmp != slow)
                {
                    slow = slow->next;
                    tmp = tmp->next;
                }
                return tmp;
            }
        }
        return nullptr;
    }
};