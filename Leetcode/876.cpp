/**
 * 876. 链表的中间结点  单指针
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
        int size = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        temp = head;
        size = size / 2;
        while (size > 0)
        {
            temp = temp->next;
            size--;
        }

        return temp;
    }
};