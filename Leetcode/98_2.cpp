/**
 * 98. 验证二叉搜索树 中序遍历
 * link：https://leetcode-cn.com/problems/validate-binary-search-tree/
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
        stack<TreeNode *> s;
        bool begin = true;
        int midval = INT_MIN;

        while (!s.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (begin)
            {
                if (root->val < midval)
                    return false;
                begin = false;
            }
            else if (root->val <= midval)
                return false;

            midval = root->val;
            root = root->right;
        }

        return true;
    }
};