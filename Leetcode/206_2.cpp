/**
 * 206. 反转链表    递归
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

/**
 * node_1 -> node_2 -> node_3 <- node_4 <- node_5
 * |<-    not reversed  ->|<-    reversed     ->|
 * node_2 -> next -> next = node_3 ->next = node_2
 */

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        return reverse(head);
    }

    ListNode *reverse(ListNode *head)
    {
        if (head->next == nullptr)
            return head;

        ListNode *res = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return res;
    }
};