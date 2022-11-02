/**
 * 1668. 最大重复子字符串
 * link：https://leetcode.cn/problems/maximum-repeating-substring/
 */

class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        int m = sequence.size(), n = word.size();
        if (n > m)
        {
            return 0;
        }

        auto stringCompare = [](const string &a, const string &b) -> bool
        {
            int aLen = a.size(), bLen = b.size();
            if (aLen != bLen)
            {
                return false;
            }
            for (int i = 0; i < aLen; i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }
            return true;
        };

        vector<int> dp(m - n + 1, 0);
        for (int i = 0; i <= m - n; i++)
        {
            if (stringCompare(sequence.substr(i, n), word))
            {
                dp[i] = (i - n >= 0 ? dp[i - n] : 0) + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};