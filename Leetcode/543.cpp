/**
 * 543. 二叉树的直径 dfs
 * link：https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
 * The maximum diameter length of each subtree is the sum 
 * of the maximum diameter length of the left and right subtrees
 */
class Solution {
public:
    int len = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return this->len;
    }

    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        this->len = max(this->len,leftDepth+rightDepth);
        return max(leftDepth,rightDepth)+1;
    }
};