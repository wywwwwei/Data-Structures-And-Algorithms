/**
 * 23. 合并K个排序链表 分治 —— 两两合并
 * link：https://leetcode-cn.com/problems/merge-k-sorted-lists/
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
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode *result = nullptr;
        ListNode *cur = nullptr;

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

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int count = lists.size();
        if (count == 0)
            return nullptr;

        while (count > 1)
        {
            int cmpTimes = count / 2;
            for (int i = 0; i < cmpTimes; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + cmpTimes]);

            if (count % 2 != 0)
                lists[cmpTimes] = lists[cmpTimes * 2];

            count = (count + 1) / 2;
        }
        return lists[0];
    }
};