/**
 * 429. N叉树的层序遍历
 * link：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
 */

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};
        queue<Node *> nodes;

        vector<vector<int>> result;
        nodes.push(root);
        while (!nodes.empty())
        {
            int len = nodes.size();
            vector<int> cur;
            for (int i = 0; i < len; i++)
            {
                Node *tmp = nodes.front();
                nodes.pop();
                cur.push_back(tmp->val);
                for (const auto &child : tmp->children)
                {
                    nodes.push(child);
                }
            }
            result.push_back(cur);
        }

        return result;
    }
};