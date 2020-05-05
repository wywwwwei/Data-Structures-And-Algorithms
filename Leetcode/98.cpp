/**
 * 98. 验证二叉搜索树
 * link：https://leetcode-cn.com/problems/validate-binary-search-tree/
 */

/**
 * A binary search tree
 *                                                  [INT_MIN, INT_AMX]
 *                                          /                               \
 *                  [INT_MIN, parent->val)                                  (parent->val, INT_MAX]
 *                  /              \                                            /               \
 * [INT_MIN, parent->val)   (parent->val, grandparent->val) (grandparent->val, parent->val) (parent->val, INT_MAX]
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
    bool isValidBST(TreeNode *root)
    {
        return dfs(root, INT_MIN, INT_MAX, true, true);
    }

    bool dfs(TreeNode *root, int minval, int maxval, bool leftEQ, bool rightEQ)
    {
        if (root == nullptr)
            return true;
        if ((leftEQ ? root->val >= minval : root->val > minval) && (rightEQ ? root->val <= maxval : root->val < maxval))
            return dfs(root->left, minval, root->val, leftEQ, false) && dfs(root->right, root->val, maxval, false, rightEQ);
        return false;
    }
};