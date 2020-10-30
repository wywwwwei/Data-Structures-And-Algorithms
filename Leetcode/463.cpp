/**
 * 463. 岛屿的周长 迭代
 * link：https://leetcode-cn.com/problems/island-perimeter/
 */

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    if (i - 1 < 0 || grid[i - 1][j] == 0)
                        result++;
                    if (i + 1 >= n || grid[i + 1][j] == 0)
                        result++;
                    if (j - 1 < 0 || grid[i][j - 1] == 0)
                        result++;
                    if (j + 1 >= m || grid[i][j + 1] == 0)
                        result++;
                }
            }
        }
        return result;
    }
};