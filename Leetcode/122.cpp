/**
 * 122. 买卖股票的最佳时机 II
 * link：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp_none = 0, dp_own = -prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            int tmp = dp_none;
            dp_none = max(dp_own + prices[i], dp_none);
            dp_own = max(tmp - prices[i], dp_own);
        }
        return dp_none;
    }
};