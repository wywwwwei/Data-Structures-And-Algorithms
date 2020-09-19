/**
 * 404. 左叶子之和
 * link：https://leetcode-cn.com/problems/sum-of-left-leaves/
 */

class Solution
{
    int sum = 0;

public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root != nullptr)
            dfs(root);
        return sum;
    }

    bool isLeaf(TreeNode *cur)
    {
        return cur->left == nullptr && cur->right == nullptr;
    }

    void dfs(TreeNode *cur)
    {
        if (cur->left != nullptr)
        {
            if (isLeaf(cur->left))
                sum += cur->left->val;
            else
                dfs(cur->left);
        }
        if (cur->right != nullptr)
            dfs(cur->right);
    }
};