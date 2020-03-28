/**
 * 1162. 地图分析 动态规划
 * link：https://leetcode-cn.com/problems/as-far-from-land-as-possible/
 */

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int result = -1;
        int grid_len = grid.size();
        int land = 0;
        int sea = 0;
        vector<vector<int>> dp(grid_len, vector<int>(grid_len, INT_MAX - 1));

        for (int i = 0; i < grid_len; i++)
        {
            for (int j = 0; j < grid_len; j++)
            {
                if (grid[i][j])
                {
                    land++;
                    dp[i][j] = 0;
                }
                else
                {
                    sea++;
                }
            }
        }
        if (land == 0 || sea == 0)
            return -1;

        for (int i = 0; i < grid_len; i++)
        {
            for (int j = 0; j < grid_len; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (i - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j - 1 >= 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }

        for (int i = grid_len - 1; i >= 0; i--)
        {
            for (int j = grid_len - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                {
                    if (i + 1 < grid_len)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j + 1 < grid_len)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }

        for (int i = 0; i < grid_len; i++)
        {
            for (int j = 0; j < grid_len; j++)
            {
                result = max(result, dp[i][j]);
            }
        }

        return result;
    }
};