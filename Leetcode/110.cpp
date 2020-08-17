/**
 * 110. 平衡二叉树
 * link：https://leetcode-cn.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int l, r;
        if ((l = height(root->left)) >= 0 && (r = height(root->right)) >= 0 && abs(l - r) <= 1)
            return max(l, r) + 1;
        return -1;
    }
};