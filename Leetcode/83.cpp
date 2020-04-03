/**
 * 83. 删除排序链表中的重复元素
 * link：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;

        while (cur != nullptr && cur->next != nullptr)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else
            {
                cur = cur->next;
            }
        }

        return head;
    }
};