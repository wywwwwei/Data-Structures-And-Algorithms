/**
 * 235. 二叉搜索树的最近公共祖先    Recursion / Iteration
 * link：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */

// Recursion
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};

// Iteration
// class Solution
// {
// public:
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         TreeNode *cur = root;
//         while (cur != nullptr)
//         {
//             if (cur->val > p->val && cur->val > q->val)
//                 cur = cur->left;
//             else if (cur->val < p->val && cur->val < q->val)
//                 cur = cur->right;
//             else
//                 return cur;
//         }
//         return nullptr;
//     }
// };