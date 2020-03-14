/**
 * 695. 岛屿的最大面积 dfs
 * link：https://leetcode-cn.com/problems/max-area-of-island/
 */

class Solution
{
    int operation[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maximum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    maximum = max(maximum, dfs(grid, i, j));
            }
        }

        return maximum;
    }

    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (grid[x][y] == 0)
            return 0;

        int res = 1;
        grid[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int dx = x + operation[i][0];
            int dy = y + operation[i][1];
            if (dx < grid.size() && dx >= 0 && dy >= 0 && dy < grid[0].size())
            {
                res += dfs(grid, dx, dy);
            }
        }

        return res;
    }
};