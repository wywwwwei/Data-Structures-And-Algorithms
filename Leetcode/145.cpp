/**
 * 145. 二叉树的后序遍历 Morris
 * link：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 */

class Solution
{
    void addPath(vector<int> &path, TreeNode *root)
    {
        vector<int> tmp;
        while (root != nullptr)
        {
            tmp.emplace_back(root->val);
            root = root->right;
        }
        reverse(tmp.begin(), tmp.end());

        for (const int &t : tmp)
            path.emplace_back(t);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        TreeNode *cur = root;
        TreeNode *predecessor = nullptr;
        vector<int> result;

        while (cur)
        {
            if (cur->left)
            {
                predecessor = cur->left;
                while (predecessor->right != nullptr && predecessor->right != cur)
                    predecessor = predecessor->right;

                if (predecessor->right == nullptr)
                {
                    predecessor->right = cur;
                    cur = cur->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    addPath(result, cur->left);
                    cur = cur->right;
                }
            }
            else
            {
                cur = cur->right;
            }
        }
        addPath(result, root);
        return result;
    }
};