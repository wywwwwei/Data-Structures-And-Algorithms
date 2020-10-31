/**
 * 140. 单词拆分 II
 * link：https://leetcode-cn.com/problems/word-break-ii/
 */

class Solution
{
    unordered_set<string> dict;
    vector<vector<string>> store;
    int max_len = 0;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (const auto &word : wordDict)
        {
            dict.insert(word);
            max_len = max(max_len, (int)word.length());
        }

        // Filtering out the cases where the words in dictionary cannot build the complete string, 
        // but they can build long prefixes which may cause too deep recursion and too many branches.
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
        if(!dp[s.size()])
            return {};

        store.resize(s.size() + 1, vector<string>());
        backtrace(s, 0);
        return store[0];
    }

    void backtrace(const string &s, int index)
    {
        if (store[index].size() == 0)
        {
            if (index == s.length())
            {
                store[index].push_back("");
                return;
            }
            for (int i = index + 1; i <= s.length() && i <= index + max_len; i++)
            {
                string cur = s.substr(index, i - index);
                if (dict.find(cur) != dict.end())
                {
                    backtrace(s, i);
                    for (const string &tmp : store[i])
                        store[index].push_back((tmp.empty() ? cur : cur + " " + tmp));
                }
            }
        }
    }
};