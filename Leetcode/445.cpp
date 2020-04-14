/**
 * 445. 两数相加 II
 * link：https://leetcode-cn.com/problems/add-two-numbers-ii/
 */

/**
 * Add two numbers -> Addition with carry -> inverse the list -> can not modify input lists -> stack
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> left, right;
        ListNode *temp_l = l1, *temp_r = l2;
        for (ListNode *temp = l1; temp != nullptr; temp = temp->next)
            left.push(temp);
        for (ListNode *temp = l2; temp != nullptr; temp = temp->next)
            right.push(temp);

        ListNode *cur = nullptr;
        bool carry = false;
        while (!left.empty() && !right.empty())
        {
            int sum = left.top()->val + right.top()->val + (carry ? 1 : 0);
            left.pop();
            right.pop();
            carry = (sum >= 10);

            ListNode *higher = new ListNode(sum % 10);
            higher->next = cur;
            cur = higher;
        }

        while (!left.empty())
        {
            int sum = left.top()->val + (carry ? 1 : 0);
            left.pop();
            carry = (sum >= 10);

            ListNode *higher = new ListNode(sum % 10);
            higher->next = cur;
            cur = higher;
        }

        while (!right.empty())
        {
            int sum = right.top()->val + (carry ? 1 : 0);
            right.pop();
            carry = (sum >= 10);

            ListNode *higher = new ListNode(sum % 10);
            higher->next = cur;
            cur = higher;
        }

        if (carry)
        {
            ListNode *highest = new ListNode(1);
            highest->next = cur;
            cur = highest;
        }

        return cur;
    }
};