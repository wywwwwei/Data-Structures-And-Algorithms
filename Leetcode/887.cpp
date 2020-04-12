/**
 * 887. 鸡蛋掉落 dp + 决策单调性
 * link：https://leetcode-cn.com/problems/super-egg-drop/
 */

/**
 *  According to the state transition equation:
 *  dp[k][n] = 1 + min{ max(dp[k-1][x-1], dp[k][n-x]) }  1 <= x <= n
 *  See the specific meaning here: https://assets.leetcode-cn.com/solution-static/887_fig1.jpg
 * 
 *  It can be seen that we only need to know K-1 to derive K.
 *  Simplify the above formula:
 *  denote dp[k] with dp_k and dp[k-1] with dp_k_1 
 *  dp_k[n] = 1 + min{ max(dp_k_1[x-1], dp_k[n-x]) }  1 <= x <= n
 * 
 *  dp[k-1][x-1] does not change as n becomes larger, 
 *  and dp[k][n - x] as n becomes larger, the range of x and each value will become larger, 
 *  because dp[k] increases with the increase of (n - x) (n increases or x decreases)
 *  so their intersection point (x) keeps increasing, 
 *  so dp[k][n] only needs to find the intersection point from the x value of dp[k][n-1]
 */
class Solution
{
public:
    int superEggDrop(int K, int N)
    {
        vector<int> dp_k_1(N + 1, 0);
        for (int i = 0; i <= N; i++)
            dp_k_1[i] = i;

        for (int i = 1; i < K; i++)
        {
            vector<int> dp_k(N + 1, 0);
            
            //Decision monotony
            int x = 1;
            for (int n = 1; n <= N; n++)
            {
                while (x < n && max(dp_k_1[x - 1], dp_k[n - x]) >= max(dp_k_1[x], dp_k[n - x - 1]))
                    x++;
                dp_k[n] = 1 + max(dp_k_1[x - 1], dp_k[n - x]);
            }
            for (int n = 1; n <= N; ++n)
                dp_k_1[n] = dp_k[n];
        }

        return dp_k_1[N];
    }
};