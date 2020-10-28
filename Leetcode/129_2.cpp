/**
 * 129. 求根到叶子节点数字之和
 * link：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 */

class Solution
{
    int result = 0;

public:
    int sumNumbers(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode *cur, int cur_val)
    {
        cur_val = cur_val * 10 + cur->val;
        if (cur->left == nullptr && cur->right == nullptr)
        {
            result += cur_val;
            return;
        }
        if (cur->left)
            dfs(cur->left, cur_val);
        if (cur->right)
            dfs(cur->right, cur_val);
    }
};