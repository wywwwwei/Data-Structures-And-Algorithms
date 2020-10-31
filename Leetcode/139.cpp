/**
 * 139. 单词拆分
 * link：https://leetcode-cn.com/problems/word-break/
 */

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        int max_len = 0;
        for (const auto &word : wordDict)
        {
            dict.insert(word);
            max_len = max(max_len, (int)word.length());
        }

        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i - 1; j >= 0 && j >= i - max_len; j--)
            {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};