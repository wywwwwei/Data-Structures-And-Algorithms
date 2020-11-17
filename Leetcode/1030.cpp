/**
 * 1030. 距离顺序排列矩阵单元格
 * link：https://leetcode-cn.com/problems/matrix-cells-in-distance-order/
 */

/**
 * BFS without space optimization
 */
class Solution
{
    using dint = pair<int, int>;

public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        vector<vector<bool>> visit(R, vector<bool>(C, false));

        vector<vector<int>> result(R * C, vector<int>(2, 0));
        int count = 0;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        queue<dint> q;
        q.push(make_pair(r0, c0));
        visit[r0][c0] = true;

        while (!q.empty())
        {
            dint a = q.front();
            q.pop();

            result[count][0] = a.first;
            result[count++][1] = a.second;

            for (int i = 0; i < 4; i++)
            {
                int dx = a.first + move[i][0];
                int dy = a.second + move[i][1];
                if (dx < 0 || dx >= R || dy < 0 || dy >= C || visit[dx][dy])
                    continue;
                visit[dx][dy] = true;
                q.push({dx, dy});
            }
        }

        return result;
    }
};
