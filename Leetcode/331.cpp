/**
 * 331. 验证二叉树的前序序列化
 * link：https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
 */

class Solution
{
    int n;

public:
    bool isValidSerialization(string preorder)
    {
        n = preorder.length();
        int idx = 0;

        return rec(preorder, idx) && idx == n;  // without redundant nodes
    }

    bool rec(string &s, int &idx)
    {
        if (idx >= n)
            return false;

        if (s[idx] == '#')
        {
            ++idx;
            return true;
        }

        while (idx < n && isdigit(s[idx]))
            ++idx;

        ++idx; //skip ','
        bool a = rec(s, idx);       // build left tree

        ++idx; //skip ','
        return a && rec(s, idx);    // build right tree
    }
};