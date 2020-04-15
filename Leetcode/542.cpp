/**
 * 542. 01 矩阵 dp
 * link：https://leetcode-cn.com/problems/01-matrix/
 * Similar to this question：https://leetcode-cn.com/problems/as-far-from-land-as-possible/
 */

/**
 * Method 1: bfs (Use all positions with a value of 0 as the initial queue)
 * Method 2: dp (The distance of the nearest 0 of each position is equal to the minimum among those four adjacent positions + 1)
 */
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m, n + m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    result[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    result[i][j] = min(1 + result[i - 1][j], result[i][j]);
                if (j > 0)
                    result[i][j] = min(1 + result[i][j - 1], result[i][j]);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (matrix[i][j] == 0)
                    continue;
                if (i < n - 1)
                    result[i][j] = min(1 + result[i + 1][j], result[i][j]);
                if (j < m - 1)
                    result[i][j] = min(1 + result[i][j + 1], result[i][j]);
            }
        }
        return result;
    }
};