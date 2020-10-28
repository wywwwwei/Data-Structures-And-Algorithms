/**
 * 129. 求根到叶子节点数字之和
 * link：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 */

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int result = 0;
        queue<TreeNode *> store;
        store.push(root);

        while (!store.empty())
        {
            TreeNode *tmp = store.front();
            store.pop();

            if (tmp->left == nullptr && tmp->right == nullptr)
            {
                result += tmp->val;
                continue;
            }
            if (tmp->left)
            {
                tmp->left->val += tmp->val * 10;
                store.push(tmp->left);
            }
            if (tmp->right)
            {
                tmp->right->val += tmp->val * 10;
                store.push(tmp->right);
            }
        }

        return result;
    }
};