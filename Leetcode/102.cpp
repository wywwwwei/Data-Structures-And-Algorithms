/**
 * 102. 二叉树的层序遍历
 * link：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        vector<int> cur;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            cur.clear();
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                cur.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            result.push_back(cur);
        }
        return result;
    }
};