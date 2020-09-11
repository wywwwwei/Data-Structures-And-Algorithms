/**
 * 513. 找树左下角的值 BFS from right to left
 * link：https://leetcode-cn.com/problems/find-bottom-left-tree-value/
 */

class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> nodes;

        nodes.push(root);
        TreeNode *result;
        while (!nodes.empty())
        {
            result = nodes.front();
            nodes.pop();
            if (result->right != nullptr)
                nodes.push(result->right);
            if (result->left != nullptr)
                nodes.push(result->left);
        }
        return result->val;
    }
};