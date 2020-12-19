/**
 * 1081. 不同字符的最小子序列
 * link：https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/
 */

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        bool visit[26] = {false};
        int count[26] = {0};

        for (const char &c : s)
            ++count[c - 'a'];
        string result;
        for (const char &c : s)
        {
            if (!visit[c - 'a'])
            {
                while (!result.empty() && result.back() > c)
                {
                    if (count[result.back() - 'a'] > 0)
                    {
                        visit[result.back() - 'a'] = false;
                        result.pop_back();
                    }
                    else
                        break;
                }
                visit[c - 'a'] = true;
                result.push_back(c);
            }
            --count[c - 'a'];
        }
        return result;
    }
};