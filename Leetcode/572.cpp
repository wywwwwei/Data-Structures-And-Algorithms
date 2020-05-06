/**
 * 572. 另一个树的子树 recursion / dfs
 * link：https://leetcode-cn.com/problems/subtree-of-another-tree/
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

/**
 * Other method:
 * 1. traverse the tree to get the sequence and use kmp to find subsequence
 * 2. tree hash.  For each subtree coresspond to a hash value.  
 */

class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
            return true;
        else if (s == nullptr || t == nullptr)
            return false;

        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
            return true;
        else if (s == nullptr || t == nullptr)
            return false;

        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};