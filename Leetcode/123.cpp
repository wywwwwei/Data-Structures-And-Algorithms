/**
 * 123. 买卖股票的最佳时机 III
 * link：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

/**
 * i days, 0/1/2 transcations, 0/1 stocks, prices[j]
 * dp[i][0][0] = dp[i-1][0][0]) = 0
 * dp[i][0][1] = max(~, dp[i][0][0] - prices[j])
 * dp[i][1][0] = max(~, dp[i][0][1] + prices[j])
 * dp[i][1][1] = max(~, dp[i][1][0] - prices[j])
 * dp[i][2][0] = max(~, dp[i][1][1] + prices[j])
 * 
 * ~ = dp[i-1][][]
 * 
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 0)
            return 0;

        int buy1 = -prices[0];
        int transcation = 0;
        int buy2 = -prices[0];
        int transcation2 = 0;

        for (int i = 1; i < n; i++)
        {
            buy1 = max(buy1, -prices[i]);
            transcation = max(transcation, buy1 + prices[i]);
            buy2 = max(buy2, transcation - prices[i]);
            transcation2 = max(transcation2, buy2 + prices[i]);
        }

        return transcation2;
    }
};