/**
 * 538. 把二叉搜索树转换为累加树    Morris
 * link：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 */

class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        TreeNode *node = root;
        TreeNode *successor = nullptr;

        while (node != nullptr)
        {
            if (node->right == nullptr)
            {
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
            else
            {
                successor = getSuccessor(node);
                if (successor->left != nullptr)
                {
                    successor->left = nullptr;
                    sum += node->val;
                    node->val = sum;
                    node = node->left;
                }
                else
                {
                    successor->left = node;
                    node = node->right;
                }
            }
        }
        return root;
    }

    TreeNode *getSuccessor(TreeNode *cur)
    {
        TreeNode *find = cur->right;
        while (find->left != nullptr && find->left != cur)
            find = find->left;
        return find;
    }
};