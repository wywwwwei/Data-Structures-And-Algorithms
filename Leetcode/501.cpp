/**
 * 501. 二叉搜索树中的众数
 * link：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 */

class Solution
{
    int last = 0;
    int maxCount = 0;
    int curCount = 0;
    vector<int> result;

    void update(int val)
    {
        if (last == val)
        {
            curCount++;
        }
        else
        {
            //To avoid rebuilding the vector multiple times, compare the curCount and maxCount only when last != val
            //But after traversing the tree, a value different from last is needed to pass in to check the count of last
            if (curCount == maxCount && maxCount > 0)
            {
                result.push_back(last);
            }
            else if (curCount > maxCount)
            {
                result.clear();
                result.push_back(last);
                maxCount = curCount;
            }
            last = val;
            curCount = 1;
        }
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        TreeNode *cur = root;
        TreeNode *predecessor = nullptr;

        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                update(cur->val);
                cur = cur->right;
            }
            else
            {
                predecessor = cur->left;
                while (predecessor->right != nullptr && predecessor->right != cur)
                    predecessor = predecessor->right;

                if (predecessor->right == nullptr)
                {
                    predecessor->right = cur;
                    cur = cur->left;
                }
                else
                {
                    predecessor->right = nullptr;
                    update(cur->val);
                    cur = cur->right;
                }
            }
        }

        //a value different from last
        //avoid overflow
        update(last ^ 1);
        return result;
    }
};