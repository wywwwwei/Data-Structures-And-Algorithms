/**
 * 234. 回文链表
 * link：https://leetcode-cn.com/problems/palindrome-linked-list/
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true;

        // Find the previous node of the middle node
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse Node
        ListNode *prev_node = nullptr;
        ListNode *cur_node = slow->next;
        ListNode *next_node;
        while (cur_node)
        {
            next_node = cur_node->next;
            cur_node->next = prev_node;
            prev_node = cur_node;
            cur_node = next_node;
        }

        // Compare
        cur_node = prev_node;
        while (cur_node != nullptr)
        {
            if (cur_node->val != head->val)
                return false;
            cur_node = cur_node->next;
            head = head->next;
        }

        return true;
    }
};