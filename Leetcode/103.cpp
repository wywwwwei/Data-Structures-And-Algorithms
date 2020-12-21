/**
 * 103. 二叉树的锯齿形层次遍历
 * link：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 */

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> result;
        bool right = false;
        queue<TreeNode *> store;

        store.push(root);
        while (!store.empty())
        {
            int n = store.size();
            vector<int> cur;
            for (int i = 0; i < n; i++)
            {
                TreeNode *tmp = store.front();
                store.pop();

                cur.push_back(tmp->val);

                if (tmp->left)
                    store.push(tmp->left);
                if (tmp->right)
                    store.push(tmp->right);
            }
            if (right)
                reverse(cur.begin(), cur.end());
            right = !right;
            result.push_back(move(cur));
        }

        return result;
    }
};