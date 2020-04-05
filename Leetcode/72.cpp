/**
 * 72. 编辑距离 dp
 * link：https://leetcode-cn.com/problems/edit-distance/
 */

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length(), m = word2.length();
        if (n * m == 0)
            return n + m;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int i = 0; i <= m; i++)
            dp[0][i] = i;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {

                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};