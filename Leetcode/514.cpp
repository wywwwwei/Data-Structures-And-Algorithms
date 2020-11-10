/**
 * 514. 自由之路
 * link：https://leetcode-cn.com/problems/freedom-trail/
 */

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        int m = ring.size();
        int n = key.size();

        vector<int> pos[26];
        for (int i = 0; i < m; i++)
            pos[ring[i] - 'a'].push_back(i);

        // initialize
        int dp[n][m];
        fill(dp[0], dp[n - 1] + m, n * m);

        // bound
        for (const auto &i : pos[key[0] - 'a'])
            dp[0][i] = min(i, m - i) + 1;

        for (int i = 1; i < n; i++)
        {
            for (const auto &j : pos[key[i] - 'a'])
            {
                for (const auto &k : pos[key[i - 1] - 'a'])
                {
                    int move = abs(j - k);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(move, m - move) + 1);
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < m; i++)
            result = min(result, dp[n - 1][i]);
        return result;
    }
};