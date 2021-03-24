/**
 * 82. 删除排序链表中的重复元素 II
 * link：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 */

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *dummy = new ListNode(INT_MAX, head);

        ListNode *cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) // cur points to the last node of the duplicates deleted lists
        {
            if (cur->next->val == cur->next->next->val) // equal and need to find the end
            {
                int val = cur->next->val;
                ListNode *tmp = cur->next->next->next;

                while (tmp != nullptr && tmp->val == val)
                    tmp = tmp->next;

                cur->next = tmp;
            }
            else // not equal, step forward
            {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};