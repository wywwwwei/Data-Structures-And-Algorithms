/**
 * 226. 翻转二叉树 BFS
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> nodelist;
        nodelist.push(root);
        //Pre-order traverse each non-empty node and exchange left and right nodes (subtrees)
        while(!nodelist.empty()){
            TreeNode *temp = nodelist.front();
            nodelist.pop();
            if(temp == NULL)continue;
            TreeNode *temp2 = temp->left;
            temp->left = temp->right;
            temp->right = temp2;
            nodelist.push(temp->left);
            nodelist.push(temp->right);
        }
        return root;
    }
};