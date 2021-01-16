/**
 * 803. 打砖块  Union-Find
 * link：https://leetcode-cn.com/problems/bricks-falling-when-hit/
 */

class Solution
{
    int unionSize = 0;
    inline int index(int row, int col, int col_size)
    {
        return row * col_size + col;
    }
    
    int findParent(vector<int> &parent, int a)
    {
        if (parent[a] != a)
            parent[a] = findParent(parent, parent[a]);
        return parent[a];
    }

    void merge(vector<int> &parent, vector<int> &setSize, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        if (parent_a == parent_b)
            return;
        parent[parent_a] = parent_b;
        setSize[parent_b] += setSize[parent_a];
    }
    static constexpr int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> newGrid(grid);
        for (const auto &hit : hits)
            newGrid[hit[0]][hit[1]] = 0;

        unionSize = m * n;
        vector<int> parent(unionSize + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> setSize(unionSize + 1, 1);

        for (int j = 0; j < n; j++)
            if (newGrid[0][j] == 1)
                merge(parent, setSize, j, unionSize);

        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (newGrid[i][j] == 1)
                {
                    if (newGrid[i - 1][j] == 1)
                        merge(parent, setSize, index(i, j, n), index(i - 1, j, n));
                    if (j > 0 && newGrid[i][j - 1] == 1)
                        merge(parent, setSize, index(i, j, n), index(i, j - 1, n));
                }
            }
        }

        int k = hits.size();
        vector<int> result(k);
        for (int i = k - 1; i >= 0; --i)
        {
            int x = hits[i][0];
            int y = hits[i][1];

            if (grid[x][y] == 0)
                continue;

            int oldCount = setSize[findParent(parent, unionSize)];
            if (x == 0)
                merge(parent, setSize, y, unionSize);

            for (int i = 0; i < 4; i++)
            {
                int dx = x + direction[i][0];
                int dy = y + direction[i][1];
                if (dx < 0 || dx >= m || dy < 0 || dy >= n)
                    continue;
                if (newGrid[dx][dy] == 1)
                    merge(parent, setSize, index(x, y, n), index(dx, dy, n));
            }
            int newCount = setSize[findParent(parent, unionSize)];
            result[i] = max(0, newCount - oldCount - 1);
            newGrid[x][y] = 1;
        }

        return result;
    }
};