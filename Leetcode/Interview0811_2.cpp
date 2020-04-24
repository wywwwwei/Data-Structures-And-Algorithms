/**
 * 面试题 08.11. 硬币 dp
 * link：https://leetcode-cn.com/problems/coin-lcci/
 */

/**
 * Typical complete knapsack problem
 * the number of types of coins available is denoted as i, the face value of the i-th coin is denoted as c(i)
 * f[i][v] = f[i-1][v] + f[i-1][v - k * c(i)]  1 <= k <= v/c(i)
 *         = f[i-1][v] + f[i][v - c(i)]
 * 
 * Because we only need to record f[i] and f[i-1], 
 * and when we compute f[i][v], we will not use f[i][>= v].
 * 
 * Simplify it to f[v] = f[v] + f[v - c(i)]
 */
class Solution
{
public:
    int waysToChange(int n)
    {
        const int mod = 1000000007;
        const int values[] = {1, 5, 10, 25};
        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = values[i]; j <= n; j++)
            {
                dp[j] = (dp[j] + dp[j - values[i]]) % mod;
            }
        }
        return dp[n];
    }
};