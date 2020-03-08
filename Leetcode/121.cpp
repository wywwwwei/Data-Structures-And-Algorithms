/**
 * 121. 买卖股票的最佳时机 dp
 * link：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 */

/**
 * State transition equation: max profit today = (max profit yesterday , price today - min price previous days) 
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (auto price : prices)
        {
            max_profit = max(max_profit, price - min_price);
            min_price = min(min_price, price);
        }

        return max_profit;
    }
};