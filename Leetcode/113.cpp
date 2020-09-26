/**
 * 113. 路径总和 II  dfs
 * link：https://leetcode-cn.com/problems/path-sum-ii/
 */

class Solution
{
    vector<int> path;
    vector<vector<int>> result;
    int target;
    int curSum = 0;

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return {};
        target = sum;
        dfs(root);
        return result;
    }

    void dfs(TreeNode *cur)
    {
        curSum += cur->val;
        path.push_back(cur->val);

        if (cur->left != nullptr)
            dfs(cur->left);
        if (cur->right != nullptr)
            dfs(cur->right);
        if (cur->left == nullptr && cur->right == nullptr)
        {
            if (curSum == target)
                result.push_back(path);
        }

        path.pop_back();
        curSum -= cur->val;
    }
};