/**
 * 778. 水位上升的泳池中游泳
 * link：https://leetcode-cn.com/problems/swim-in-rising-water/
 */

class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = findParent(parent, parent[x]);
    }

    bool merge(vector<int> &parent, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        if (parent_a == parent_b)
            return false;
        parent[parent_a] = parent_b;
        return true;
    }

    static constexpr int step[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> parent(m * n);
        iota(parent.begin(), parent.end(), 0);

        vector<int> idx(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                idx[grid[i][j]] = i * n + j;
            }
        }

        for (int i = 0; i < m * n; i++)
        {
            int x = idx[i] / n;
            int y = idx[i] % n;

            for (int j = 0; j < 4; j++)
            {
                int dx = x + step[j][0];
                int dy = y + step[j][1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n)
                    continue;
                if (grid[dx][dy] <= i)
                {
                    if (merge(parent, x * n + y, dx * n + dy) && findParent(parent, 0) == findParent(parent, m * n - 1))
                    {
                        return i;
                    }
                }
            }
        }

        return -1;
    }
};