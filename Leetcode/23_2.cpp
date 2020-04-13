/**
 * 23. 合并K个排序链表 堆
 * link：https://leetcode-cn.com/problems/merge-k-sorted-lists/
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (ListNode *&l : lists)
            if (l != nullptr)
                pq.push(l);

        ListNode *result = new ListNode(-1);
        ListNode *temp = result;
        while (!pq.empty())
        {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if (temp->next != nullptr)
                pq.push(temp->next);
        }

        return result->next;
    }
};