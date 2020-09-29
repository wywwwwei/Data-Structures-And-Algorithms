/**
 * 701. 二叉搜索树中的插入操作  Recursion
 * link：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
 */

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);
        insert(root, val);
        return root;
    }

    void insert(TreeNode *root, int &val)
    {
        if (root->val < val)
        {
            if (root->right)
                insert(root->right, val);
            else
                root->right = new TreeNode(val);
        }
        else
        {
            if (root->left)
                insert(root->left, val);
            else
                root->left = new TreeNode(val);
        }
    }
};