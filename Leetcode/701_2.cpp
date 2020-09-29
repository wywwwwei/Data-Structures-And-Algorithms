/**
 * 701. 二叉搜索树中的插入操作  Iteration
 * link：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/
 */

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
            return new TreeNode(val);

        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val < val)
            {
                if (cur->right)
                {
                    cur = cur->right;
                }
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (cur->left)
                {
                    cur = cur->left;
                }
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};