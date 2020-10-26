/**
 * 144. 二叉树的前序遍历
 * link：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 */

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
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

                if (predecessor->right)
                {
                    predecessor->right = nullptr;
                    cur = cur->right;
                }
                else
                {
                    result.push_back(cur->val);
                    predecessor->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};