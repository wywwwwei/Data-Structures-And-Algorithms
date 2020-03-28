/**
 * 1162. 地图分析 BFS
 * link：https://leetcode-cn.com/problems/as-far-from-land-as-possible/
 */

class Solution
{
public:
    struct pos
    {
        int dis;
        int x;
        int y;
    };

    int maxDistance(vector<vector<int>> &grid)
    {
        int result = 0;
        int grid_len = grid.size();

        vector<vector<bool>> visit(grid_len, vector<bool>(grid_len, false));
        queue<pos> q;

        for (int i = 0; i < grid_len; i++)
        {
            for (int j = 0; j < grid_len; j++)
            {
                if (grid[i][j])
                {
                    visit[i][j] = true;
                    q.push(pos{0, i, j});
                }
            }
        }

        if (q.empty() || q.size() == grid_len * grid_len)
            return -1;

        int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty())
        {
            pos temp = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int dx = temp.x + move[i][0];
                int dy = temp.y + move[i][1];
                if (dx < 0 || dx >= grid_len || dy < 0 || dy >= grid_len)
                    continue;

                if (!visit[dx][dy])
                {
                    visit[dx][dy] = true;
                    q.push(pos{temp.dis + 1, dx, dy});
                    result = max(result, temp.dis + 1);
                }
            }
        }
        return result;
    }
};