/**
 * 463. 岛屿的周长 dfs
 * link：https://leetcode-cn.com/problems/island-perimeter/
 */

class Solution
{
    int n;
    int m;

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        n = grid.size();
        if (n <= 0)
            return 0;
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }

    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 1;
        if (grid[x][y] == 2)
            return 0;
        grid[x][y]++;
        return dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y + 1) + dfs(grid, x, y - 1);
    }
};