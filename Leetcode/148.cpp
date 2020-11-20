/**
 * 148. 排序链表    Bottom Up Merge Sort
 * link：https://leetcode-cn.com/problems/sort-list/
 */

class Solution
{
    // temp header used in merge
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

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        tmp = new ListNode(-1);
        ListNode *curHead = new ListNode(-1, head);

        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }

        for (int i = 1; i < len; i <<= 1)
        {
            ListNode *sorted = curHead;
            ListNode *head1 = curHead->next, *tail1;
            ListNode *head2, *tail2;
            while (head1 != nullptr)
            {
                tail1 = head1;
                for (int j = 1; tail1->next != nullptr && j < i; j++)
                    tail1 = tail1->next;
                head2 = tail1->next;
                tail1->next = nullptr;

                tail2 = head2;
                ListNode *nextHead = nullptr;
                if (tail2 != nullptr)
                {
                    for (int j = 1; tail2->next != nullptr && j < i; j++)
                        tail2 = tail2->next;
                    nextHead = tail2->next;
                    tail2->next = nullptr;
                }

                sorted->next = merge(head1, head2);
                while (sorted->next != nullptr)
                    sorted = sorted->next;
                head1 = nextHead;
            }
        }

        return curHead->next;
    }
};