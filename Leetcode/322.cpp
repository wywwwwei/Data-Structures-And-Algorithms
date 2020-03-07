/**
 * 322. 零钱兑换 dp
 * link：https://leetcode-cn.com/problems/coin-change/
 */

/**
 * State transition equation
 *          -1   ;when i < 0 
 * dp[i] =  0    ;when i = 0
 *          min(dp[i], 1 + dp[i - (coin : coins)]);when i > 0
 */
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 0)
            return -1;
        else if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int coin : coins)
            {
                if (i - coin < 0)
                    continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] < amount + 1) ? dp[amount] : -1;
    }
};