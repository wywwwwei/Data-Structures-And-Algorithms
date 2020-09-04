/**
 * 257. 二叉树的所有路径
 * link：https://leetcode-cn.com/problems/binary-tree-paths/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
    vector<int> path;
    vector<string> result;

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root);
        return result;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
            return;
        path.push_back(root->val);
        if (root->left != nullptr)
            dfs(root->left);
        if (root->right != nullptr)
            dfs(root->right);
        if (root->left == nullptr && root->right == nullptr)
            push_back();
        path.pop_back();
    }

    void push_back()
    {
        string cur;
        int n = path.size();

        for (int i = 0; i < n; i++)
            cur += to_string(path[i]) + "->";
        cur.pop_back();
        cur.pop_back();

        result.push_back(cur);
    }
};