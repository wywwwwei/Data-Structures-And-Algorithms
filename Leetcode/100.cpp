/**
 * 100. 相同的树
 * link：https://leetcode-cn.com/problems/same-tree/
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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> q1, q2;

        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *t1 = q1.front();
            TreeNode *t2 = q2.front();
            q1.pop();
            q2.pop();

            if (t1 == t2)
                continue;
            if (t1 == nullptr || t2 == nullptr)
                return false;
            if (t1->val != t2->val)
                return false;

            q1.push(t1->left);
            q1.push(t1->right);
            q2.push(t2->left);
            q2.push(t2->right);
        }

        return q1.empty() && q2.empty();
    }
};