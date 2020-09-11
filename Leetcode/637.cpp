/**
 * 637. 二叉树的层平均值 level order traversal
 * link：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
 */

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        queue<TreeNode *> nodes;
        vector<double> average;

        nodes.push(root);
        while (!nodes.empty())
        {
            int cur_size = nodes.size();
            double cur_sum = 0;
            for (int i = 0; i < cur_size; i++)
            {
                TreeNode *tmp = nodes.front();
                nodes.pop();

                cur_sum += tmp->val;
                if (tmp->left != nullptr)
                    nodes.push(tmp->left);
                if (tmp->right != nullptr)
                    nodes.push(tmp->right);
            }
            average.push_back(cur_sum / cur_size);
        }
        return average;
    }
};