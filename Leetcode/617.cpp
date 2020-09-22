/**
 * 617. 合并二叉树 Recursion
 * link：https://leetcode-cn.com/problems/merge-two-binary-trees/
 */

class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr)
        {
            return t2;
        }
        if (t2 != nullptr)
        {
            t1->val += t2->val;
            t1->left = mergeTrees(t1->left, t2->left);
            t1->right = mergeTrees(t1->right, t2->right);
        }
        return t1;
    }
};