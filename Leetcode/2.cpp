/**
 * 2. 两数相加 一般的进位加减
 * link：https://leetcode-cn.com/problems/add-two-numbers/
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
        bool carry = false;
        ListNode *root = NULL, *temp = NULL, *temp1 = l1, *temp2 = l2;
        while (temp1 != NULL || temp2 != NULL)
        {
            int sum = (temp1 == NULL ? 0 : temp1->val) + (temp2 == NULL ? 0 : temp2->val) + (carry ? 1 : 0);
            //You can also choose to create a useless node before the loop to reduce this judgment
            if (temp == NULL) 
                root = temp = new ListNode(sum % 10);
            else
            {
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }
            carry = (sum >= 10);
            temp1 = temp1 != NULL ? temp1->next : NULL;
            temp2 = temp2 != NULL ? temp2->next : NULL;
        }
        if (carry)
            temp->next = new ListNode(1);
        return root;
    }
};