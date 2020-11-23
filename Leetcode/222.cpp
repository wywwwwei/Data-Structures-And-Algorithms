/**
 * 222. 完全二叉树的节点个数
 * link：https://leetcode-cn.com/problems/count-complete-tree-nodes/
 */

class Solution
{
    bool find(TreeNode *root, int depth, int val)
    {
        int pos = 1 << (depth - 1);
        while (root != nullptr && pos != 0)
        {
            if (val & pos)
                root = root->right;
            else
                root = root->left;
            pos >>= 1;
        }
        return root != nullptr;
    }

public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int depth = 0;
        for (TreeNode *tmp = root; tmp->left != nullptr; tmp = tmp->left)
            depth++;

        int left = 1 << depth;
        int right = (1 << (depth + 1)) - 1;
        while (left < right)
        {
            int mid = (right - left + 1) / 2 + left;
            if (find(root, depth, mid))
                left = mid;
            else
                right = mid - 1;
        }

        return left;
    }
};