/**
 * 559. N叉树的最大深度 recursion
 * link：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/
 */

class Solution
{
public:
    int maxDepth(Node *root)
    {
        return height(root);
    }

    int height(const Node *cur)
    {
        if (cur == nullptr)
        {
            return 0;
        }
        else if (cur->children.size() == 0)
        {
            return 1;
        }
        int max_height = INT_MIN;
        for (const auto &child : cur->children)
        {
            max_height = max(max_height, height(child));
        }
        return max_height + 1;
    }
};