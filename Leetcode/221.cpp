/**
 * 221. 最大正方形 dp
 * link：https://leetcode-cn.com/problems/maximal-square/
 */

/**
 *  f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1 
 *  
 *  simplify
 *  
 *  Denote f[i-1][j-1] which is f[j-1] before this round of replacement as variable record
 *  f[j] = min(record, f[j], f[j-1]) + 1
 */

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() <= 0)
            return 0;
        vector<int> dp(matrix[0].size() + 1, 0);

        int res = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int dp_upper_left = 0;
            int next = 0;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                next = dp[j + 1];
                if (matrix[i][j] == '1')
                {
                    dp[j + 1] = min(dp_upper_left, min(dp[j + 1], dp[j])) + 1;
                    res = max(res, dp[j + 1]);
                }
                else
                    dp[j + 1] = 0;
                dp_upper_left = next;
            }
        }

        return res * res;
    }
};