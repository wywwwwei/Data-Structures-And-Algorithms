/**
 * 143. 重排链表
 * link：https://leetcode-cn.com/problems/reorder-list/
 */

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;

        // Find the previous node of the middle node
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the right half nodes
        ListNode *prev_node = nullptr;
        ListNode *cur_node = slow->next;
        ListNode *&next_node = fast;
        while (cur_node != nullptr)
        {
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }
        slow->next = nullptr;

        // Merge
        ListNode *first = head;
        ListNode *&second = prev_node;
        while (second != nullptr)
        {
            next_node = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = next_node;
        }
    }
};