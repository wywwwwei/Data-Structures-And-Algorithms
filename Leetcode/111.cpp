/**
 * 111. 二叉树的最小深度 层级遍历
 * link：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 */

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int depth = 0;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            int cur = q.size();
            depth++;
            for (int i = 0; i < cur; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();

                if (tmp->left == nullptr && tmp->right == nullptr)
                    return depth;
                if (tmp->left != nullptr)
                    q.push(tmp->left);
                if (tmp->right != nullptr)
                    q.push(tmp->right);
            }
        }
        return depth;
    }
};