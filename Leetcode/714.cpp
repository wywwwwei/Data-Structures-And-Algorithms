/**
 * 714. 买卖股票的最佳时机含手续费
 * link：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int own = -prices[0], sell = 0;
        for (const int &price : prices)
        {
            int tmp = own;
            own = max(own, sell - price);
            sell = max(sell, tmp + price - fee);
        }
        return sell;
    }
};