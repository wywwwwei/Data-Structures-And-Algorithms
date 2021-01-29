/**
 * 1631. 最小体力消耗路径   Dijkstra
 * link：https://leetcode-cn.com/problems/path-with-minimum-effort/
 */

class Solution
{
    static constexpr int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        auto pathCmp = [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>, const vector<int>)>> q(pathCmp);

        vector<int> dist(m * n, INT_MAX);
        vector<bool> visit(m * n, false);
        q.emplace(vector<int>{0, 0, 0});
        dist[0] = 0;

        while (!q.empty())
        {
            auto cur = q.top();
            q.pop();

            int idx = cur[0] * n + cur[1];
            if (visit[idx])
                continue;

            if (cur[0] == m - 1 && cur[1] == n - 1)
                break;

            visit[idx] = true;
            for (int i = 0; i < 4; i++)
            {
                int dx = cur[0] + move[i][0];
                int dy = cur[1] + move[i][1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n)
                    continue;
                if (max(cur[2], abs(heights[cur[0]][cur[1]] - heights[dx][dy])) < dist[dx * n + dy])
                {
                    dist[dx * n + dy] = max(cur[2], abs(heights[cur[0]][cur[1]] - heights[dx][dy]));
                    q.emplace(vector<int>{dx, dy, dist[dx * n + dy]});
                }
            }
        }

        return dist[m * n - 1];
    }
};