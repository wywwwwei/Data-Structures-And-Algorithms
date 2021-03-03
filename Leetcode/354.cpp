/**
 * 354. 俄罗斯套娃信封问题  LIS
 * link：https://leetcode-cn.com/problems/russian-doll-envelopes/
 */

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n <= 0)
            return 0;

        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        vector<int> dp(n + 1, 1);
        int result = 1;

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            result = max(result, dp[i]);
        }

        return result;
    }
};