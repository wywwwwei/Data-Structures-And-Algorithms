/**
 * 206. 反转链表    迭代
 * link：https://leetcode-cn.com/problems/reverse-linked-list/
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *first = nullptr, *second = head;
        ListNode *tmp = nullptr;

        while (second != nullptr)
        {
            tmp = second->next;
            second->next = first;
            first = second;
            second = tmp;
        }

        return first;
    }
};