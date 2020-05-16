/**
 * 25. K 个一组翻转链表
 * link：https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *newNode = new ListNode(-1);
        newNode->next = head;

        ListNode *group_head = head;
        ListNode *group_end = head;     //next group header
        ListNode *group_tail = nullptr;
        ListNode *last_group = newNode;

        int section = 0;
        while (group_head != nullptr)
        {
            while (section < k && group_end != nullptr)
            {
                group_end = group_end->next;
                section++;
            }
            if (section == k)
            {
                group_tail = reverseList(group_head, group_end);
                last_group->next = group_tail;
                last_group = group_head;
                section = 0;
            }
            else if (section < k)
            {
                last_group->next = group_head;
            }
            group_head = group_end;
        }

        return newNode->next;
    }

    ListNode *reverseList(ListNode *head, ListNode *tail)
    {
        ListNode *first = nullptr, *second = head;
        ListNode *tmp = nullptr;

        while (second != tail)
        {
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }

        return first;
    }
};