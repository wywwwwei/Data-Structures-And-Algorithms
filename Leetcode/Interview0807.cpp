/**
 * 面试题 08.07. 无重复字符串的排列组合 深搜
 * link：https://leetcode-cn.com/problems/permutation-i-lcci/
 */

class Solution
{
    vector<string> result;

public:
    vector<string> permutation(string S)
    {
        dfs(S, 0);
        return result;
    }

    void dfs(string &s, int depth)
    {
        if (depth == s.length())
        {
            result.emplace_back(s);
            return;
        }
        for (int i = depth; i < s.length(); i++)
        {
            swap(s[depth], s[i]);
            dfs(s, depth + 1);
            swap(s[depth], s[i]);
        }
    }
};