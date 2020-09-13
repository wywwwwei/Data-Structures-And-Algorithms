/**
 * 94. 二叉树的中序遍历 Morris Traversal
 * link：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        TreeNode *predecessor;

        while (root != nullptr)
        {
            if (root->left == nullptr)
            {
                result.push_back(root->val);
                root = root->right;
            }
            else
            {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root)
                    predecessor = predecessor->right;

                if (predecessor->right == nullptr)
                {
                    predecessor->right = root;
                    root = root->left;
                }
                else
                {
                    result.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
        }

        return result;
    }
};