/**
 * 115. 不同的子序列
 * link：https://leetcode-cn.com/problems/distinct-subsequences/
 */

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (m < n)
            return 0;

        // dp[i][j] represent the number of s[:j]'s distinct sequence of t[:i]
        // vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1));
        // for (int i = 0; i <= m; ++i)
        //     dp[0][i] = 1;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < m; ++j)
        //     {
        //         if (t[i] == s[j])
        //             dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
        //         else
        //             dp[i + 1][j + 1] = dp[i + 1][j];
        //     }
        // }
        // return dp[n][m];

        vector<unsigned int> dp(n + 1); // m >= n, so we use n
        dp[0] = 1;

        for (int i = 0; i < m; ++i)
            for (int j = n - 1; j >= 0; --j)
                if (s[i] == t[j])
                    dp[j + 1] += dp[j];

        return dp[n];
    }
};