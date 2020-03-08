/**
 * 141. 环形链表 快慢指针
 * link：https://leetcode-cn.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head)
    {
        ListNode *quick = head;
        ListNode *slow = head;
        while (quick)
        {
            slow = slow->next;
            if (quick->next == NULL)
            {
                return false;
            }
            quick = quick->next->next;
            if (quick && quick == slow)
            {
                return true;
            }
        }
        return false;
    }
};