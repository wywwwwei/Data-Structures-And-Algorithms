/**
 * 959. 由斜杠划分区域
 * link：https://leetcode-cn.com/problems/regions-cut-by-slashes/
 */

class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = findParent(parent, parent[x]);
    }

    void merge(vector<int> &parent, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        parent[parent_a] = parent_b;
    }

public:
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();

        vector<int> parent(n * n * 4);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * n + j;
                if (i < n - 1)
                {
                    merge(parent, idx * 4 + 2, (idx + n) * 4);
                }
                if (j < n - 1)
                {
                    merge(parent, idx * 4 + 1, (idx + 1) * 4 + 3);
                }
                if (grid[i][j] == '/')
                {
                    merge(parent, idx * 4, idx * 4 + 3);
                    merge(parent, idx * 4 + 1, idx * 4 + 2);
                }
                else if (grid[i][j] == '\\')
                {
                    merge(parent, idx * 4, idx * 4 + 1);
                    merge(parent, idx * 4 + 2, idx * 4 + 3);
                }
                else
                {
                    merge(parent, idx * 4, idx * 4 + 1);
                    merge(parent, idx * 4 + 1, idx * 4 + 2);
                    merge(parent, idx * 4 + 2, idx * 4 + 3);
                }
            }
        }

        int result = 0;
        for (int i = 0; i < parent.size(); i++)
            if (parent[i] == i)
                ++result;

        return result;
    }
};