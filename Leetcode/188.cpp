/**
 * 188. 买卖股票的最佳时机 IV
 * link：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */

#define INVALID -10000

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 0)
            return 0;

        k = min(k, n / 2);
        vector<vector<int>> own(n, vector<int>(k + 1, 0));
        vector<vector<int>> sell(n, vector<int>(k + 1, 0));

        own[0][0] = -prices[0];
        for (int j = 1; j <= k; j++)
            own[0][j] = sell[0][j] = INVALID;

        for (int i = 1; i < n; i++)
        {
            own[i][0] = max(own[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                own[i][j] = max(own[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = max(own[i - 1][j - 1] + prices[i], sell[i - 1][j]);
            }
        }
        

        return *max_element(sell[n - 1].begin(), sell[n - 1].end());
    }
};