/**
 * 面试题 04.10. 检查子树
 * link：https://leetcode-cn.com/problems/check-subtree-lcci/
 */

class Solution
{
public:
    bool checkSubTree(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if (t1 == nullptr || t2 == nullptr)
            return false;
        return isSubTree(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

    bool isSubTree(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        else if (t1 == nullptr || t2 == nullptr)
            return false;
        if (t1->val != t2->val)
            return false;
        return isSubTree(t1->left, t2->left) && isSubTree(t1->right, t2->right);
    }
};