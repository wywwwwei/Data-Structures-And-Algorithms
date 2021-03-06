/**
 * 876. 链表的中间结点  快慢指针
 * link：https://leetcode-cn.com/problems/middle-of-the-linked-list/
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};