/**
 * 106. 从中序与后序遍历序列构造二叉树  迭代法
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

/**
 * In-order traversal：LeftNode -> RootNode -> RightNode
 * Post-order traversal：LeftNode -> RightNode -> RootNode
 * So we can compare the last value of the post-order traversal with -> we call it a
 * the last value of the in-order traversal -> we call it b
 * There are the following situations:
 *  1. When a != b occur
 *      1. a != b  it means that a has a right node / subtree (and it must be the previous value of a)
 *  2. When a = b occur
 *      1. a(b) represents a leaf node : you can start building the left node of the a's root node 
 *        and the next b must be the same as the a's root
 *      2. a(b) represents a root node : you can start building the left node of a
 *        and the left node must be the next b
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //Consider the case where the input is empty
        if(inorder.empty()||postorder.empty()) return NULL;
        
        stack<TreeNode*> rootNode;

        TreeNode *root = new TreeNode(postorder.back());
        rootNode.push(root);
        postorder.pop_back();

        while(!postorder.empty()){
            TreeNode *curRoot = nullptr;

            //After this cycle
            //Situation 1.1 --> curRoot = nullptr --> next a is the right node
            //Situation 2.1 --> loop 2 times --> curRoot = rootNode --> next b is the left node
            //Situation 2.2 --> loop 1 time --> curRoot = rootNode --> next b is the left node
            while(!rootNode.empty() && inorder.back() == rootNode.top()->val){
                curRoot = rootNode.top();
                rootNode.pop();
                inorder.pop_back();  
            }

            TreeNode *cur = new TreeNode(postorder.back());
            postorder.pop_back();

            if(!curRoot){
                rootNode.top()->right = cur;
            }else{
                curRoot->left = cur;
            }

            rootNode.push(cur);
        }
        return root;
    }
};