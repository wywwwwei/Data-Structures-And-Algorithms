/**
 * 226. 翻转二叉树  递归DFS
 * link: https://leetcode-cn.com/problems/invert-binary-tree/
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
class Solution {
public:
    //Recursively swap the left and right nodes of the current node and return when the node is null
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return root;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};