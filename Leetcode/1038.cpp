/**
 * 1038. 从二叉搜索树到更大和树    Morris 同538
 * link：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
 */

class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
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