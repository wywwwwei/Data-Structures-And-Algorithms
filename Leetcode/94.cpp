/**
 * 94. 二叉树的中序遍历 Recursion
 * link：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */

class Solution
{
    vector<int> result;

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return result;
    }

    void dfs(TreeNode *cur)
    {
        if (cur == nullptr)
            return;

        dfs(cur->left);
        result.push_back(cur->val);
        dfs(cur->right);
    }
};