/**
 * 105. 从前序与中序遍历序列构造二叉树  迭代法
 * link：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        int n = preorder.size();
        int preIndex = 0;
        int inIndex = 0;
        TreeNode *root = new TreeNode(preorder[preIndex++]);
        stack<TreeNode *> rootNodes({root});

        while (preIndex < n)
        {
            TreeNode *curRoot = nullptr;

            while (!rootNodes.empty() && inorder[inIndex] == rootNodes.top()->val)
            {
                curRoot = rootNodes.top();
                rootNodes.pop();
                inIndex++;
            }

            TreeNode *cur = new TreeNode(preorder[preIndex++]);
            if (curRoot != nullptr)
            {
                curRoot->right = cur;
            }
            else
            {
                rootNodes.top()->left = cur;
            }

            rootNodes.push(cur);
        }
        return root;
    }
};