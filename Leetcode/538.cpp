/**
 * 538. 把二叉搜索树转换为累加树    dfs
 * link：https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
 */

class Solution
{
    int sum = 0;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        // if (root == nullptr)
        //     return nullptr;

        // convertBST(root->right);
        // sum += root->val;
        // root->val = sum;
        // convertBST(root->left);

        convert(root);
        return root;
    }

    //without return value
    void convert(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        convert(cur->right);
        sum += cur->val;
        cur->val = sum;
        convert(cur->left);
    }
};
