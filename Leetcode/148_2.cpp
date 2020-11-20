/**
 * 148. 排序链表    Top Down Merge Sort
 * link：https://leetcode-cn.com/problems/sort-list/
 */

class Solution
{
    ListNode *tmp;

    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *sorted = tmp;
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val <= head2->val)
            {
                sorted->next = head1;
                head1 = head1->next;
            }
            else
            {
                sorted->next = head2;
                head2 = head2->next;
            }
            sorted = sorted->next;
        }

        if (head1 != nullptr)
            sorted->next = head1;
        if (head2 != nullptr)
            sorted->next = head2;

        return tmp->next;
    }

    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (head == nullptr)
            return nullptr;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
            {
                fast = fast->next;
            }
        }

        return merge(sortList(head, slow), sortList(slow, tail));
    }

public:
    ListNode *sortList(ListNode *head)
    {
        tmp = new ListNode(-1);
        return sortList(head, nullptr);
    }
};