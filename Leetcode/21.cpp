/**
 * 21. 合并两个有序链表 迭代/归并
 * link：https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *result = nullptr;
        ListNode *cur = nullptr;

        //We can also create a new ListNode variable to avoid judging whether it starts with l1 or l2.
        if (l1->val <= l2->val)
        {
            result = cur = l1;
            l1 = l1->next;
        }
        else
        {
            result = cur = l2;
            l2 = l2->next;
        }

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        while (l1 != NULL)
        {
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2 != NULL)
        {
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }

        return result;
    }
};