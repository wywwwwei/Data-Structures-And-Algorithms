/**
 * 1143. 最长公共子序列
 * link：https://leetcode-cn.com/problems/longest-common-subsequence/
 */

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        string *t1 = &text1, *t2 = &text2;
        if (n > m)
        {
            swap(m, n);
            swap(t1, t2);
        }

        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int last = 0;
            for (int j = 0; j < n; j++)
            {
                int tmp = dp[j + 1];
                dp[j + 1] = max(last + ((*t1)[i] == (*t2)[j] ? 1 : 0), max(dp[j], dp[j + 1]));
                last = tmp;
            }
        }
        return dp[n];
    }
};