/**
 * 107. 二叉树的层次遍历 II
 * link：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
 */

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        queue<TreeNode *> nodes;

        nodes.push(root);
        vector<int> cur_level;
        while (!nodes.empty())
        {
            int n = nodes.size();
            cur_level.clear();
            for (int i = 0; i < n; i++)
            {
                TreeNode *tmp = nodes.front();
                nodes.pop();

                cur_level.push_back(tmp->val);
                if (tmp->left != nullptr)
                    nodes.push(tmp->left);
                if (tmp->right != nullptr)
                    nodes.push(tmp->right);
            }
            result.push_back(cur_level);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};