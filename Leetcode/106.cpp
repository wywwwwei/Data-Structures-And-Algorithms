/**
 * 106. 从中序与后序遍历序列构造二叉树  递归法
 * link: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ 
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
    vector<int> inorder,postorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0,inorder.size()-1,0,postorder.size()-1);
    }

    TreeNode *build(int leftIn,int rightIn,int leftPost,int rightPost){
        if(leftIn > rightIn){
            return NULL;
        }
        //The last of the post-order traversal must be the root node of the current subtree
        int rootVal = this->postorder[rightPost];
        TreeNode *root = new TreeNode(rootVal);
        int rootIdx = leftIn;
        while(this->inorder[rootIdx]!=rootVal&&rootIdx<=rightIn)rootIdx++;
        int leftNum = rootIdx - leftIn;
        //In the in-order traversal, the left subtree is before the root node, and the right subtree is after
        //In the post-order traversal, In postorder traversal, the front nodes form the left subtree, and the back nodes form the right subtree.
        root->left = build(leftIn,rootIdx-1,leftPost,leftPost+leftNum-1);
        root->right = build(rootIdx+1,rightIn,leftPost+leftNum,rightPost-1);
        return root;
    }
};