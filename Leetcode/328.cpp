/**
 * 328. 奇偶链表
 * link：https://leetcode-cn.com/problems/odd-even-linked-list/
 */

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *evenHead = head->next;

        ListNode *evenTail = evenHead;
        ListNode *oddTail = head;
        while (oddTail->next != nullptr && evenTail->next != nullptr)
        {
            oddTail->next = oddTail->next->next;
            evenTail->next = evenTail->next->next;

            oddTail = oddTail->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;
        return head;
    }
};