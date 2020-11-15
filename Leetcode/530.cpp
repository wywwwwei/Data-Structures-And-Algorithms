/**
 * 530. 二叉搜索树的最小绝对差
 * link：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 */

class Solution
{
    int min_val = INT_MAX;
    int last = INT_MAX;

public:
    int getMinimumDifference(TreeNode *root)
    {
        dfs(root);
        return min_val;
    }

    void dfs(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        min_val = min(min_val, abs(cur->val - last));
        last = cur->val;
        dfs(cur->right);
    }
};
