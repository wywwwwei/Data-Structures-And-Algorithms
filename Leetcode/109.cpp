/**
 * 109. 有序链表转换二叉搜索树
 * link：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return listToBST(head, 0, getLen(head) - 1);
    }

    int getLen(ListNode *cur)
    {
        int len = 0;
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }
        return len;
    }

    TreeNode *listToBST(ListNode *&head, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *tmp = listToBST(head, left, mid - 1);
        TreeNode *cur = new TreeNode(head->val);
        cur->left = tmp;
        head = head->next;
        cur->right = listToBST(head, mid + 1, right);

        return cur;
    }
};