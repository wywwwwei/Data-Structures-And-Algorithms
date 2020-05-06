/**
 * 983. 最低票价 dp
 * link：https://leetcode-cn.com/problems/minimum-cost-for-tickets/
 */

/**
 * Denote days[j] as j.   Denote the first i ticket that we can use as i.
 * Denote the max index of days that the value less than x as max_index(x).
 * f[j] = min ( f[ max_index(j - duration[i]) ] )
 */

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        const int duration[] = {1, 7, 30};

        int n = days.size();
        vector<int> dp(n, INT_MAX);

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < costs.size(); i++)
            {
                //To find the max index of last duration
                int k = j - 1;
                while (k >= 0 && days[k] > days[j] - duration[i])
                    k--;

                //When k < 0, it means that days[i] is in first duration
                if (k < 0)
                {
                    dp[j] = min(dp[j], costs[i]);
                    continue;
                }

                //Use the previous duration to calculate
                dp[j] = min(dp[j], dp[k] + costs[i]);
            }
        }

        return dp[n - 1];
    }
};