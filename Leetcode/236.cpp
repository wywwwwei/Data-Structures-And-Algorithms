/**
 * 236. 二叉树的最近公共祖先 recursion
 * link：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
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
 * Other method: use hash table to record each node's parent and if the node has been visited separately
 */

/**
 * Recursion:
 * There are the following situations:
 * Denote the current access node as root
 * 1.   root == p || root == q, it means that root is currently the deepest possible answer, return root 
 * 2.   left != nullptr && right != nullptr, it means that both the left and right subtrees contain node p or node q, return root
 * 3.   Return one of the non-null results or nullptr if not present, return left ? left : right;
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return find(root, p, q);
    }

    TreeNode *find(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || p == root || q == root)
            return root;

        TreeNode *left = find(root->left, p, q);
        TreeNode *right = find(root->right, p, q);

        if (left && right)
            return root;
        else
            return left ? left : right;
    }
};