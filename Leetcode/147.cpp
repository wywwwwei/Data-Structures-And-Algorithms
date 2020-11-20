/**
 * 147. 对链表进行插入排序
 * link：https://leetcode-cn.com/problems/insertion-sort-list/
 */

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        // pre-head
        ListNode *tmp = new ListNode(INT_MIN);
        tmp->next = head;

        // separate sorted and unsorted
        // unsorted
        ListNode *unsorted = head->next;
        // sorted
        ListNode *sorted = head;

        while (unsorted != nullptr)
        {
            if (sorted->val <= unsorted->val)
            {
                sorted = sorted->next;
            }
            else
            {
                ListNode *sorted_head = tmp;
                while (unsorted->val > sorted_head->next->val)
                    sorted_head = sorted_head->next;

                sorted->next = unsorted->next;
                unsorted->next = sorted_head->next;
                sorted_head->next = unsorted;
            }
            unsorted = sorted->next;
        }
        return tmp->next;
    }
};