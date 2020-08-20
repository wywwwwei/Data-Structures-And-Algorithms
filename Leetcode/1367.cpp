/**
 * 1367. 二叉树中的列表
 * link：https://leetcode-cn.com/problems/linked-list-in-binary-tree/
 */

/**
 * SubTree Problem
 * Remind you of it: 
 * 572. subtree of another tree: https://leetcode-cn.com/problems/subtree-of-another-tree/
 */

class Solution
{
public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        return isPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool isPath(ListNode *head, TreeNode *root)
    {
        if (head == nullptr)
            return true;
        if (root == nullptr)
            return false;
        if (root->val != head->val)
            return false;
        return isPath(head->next, root->left) || isPath(head->next, root->right);
    }
};