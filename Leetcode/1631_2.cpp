/**
 * 1631. 最小体力消耗路径
 * link：https://leetcode-cn.com/problems/path-with-minimum-effort/
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

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int idx = i * n + j;
                if (i > 0)
                    edges.emplace_back(vector<int>{idx - n, idx, abs(heights[i - 1][j] - heights[i][j])});
                if (j > 0)
                    edges.emplace_back(vector<int>{idx - 1, idx, abs(heights[i][j - 1] - heights[i][j])});
            }
        }

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) -> bool { return a[2] < b[2]; });

        vector<int> parent(m * n);
        iota(parent.begin(), parent.end(), 0);
        int result = 0;

        for (const auto &edge : edges)
        {
            if (merge(parent, edge[0], edge[1]) && findParent(parent, 0) == findParent(parent, m * n - 1))
            {
                result = edge[2];
                break;
            }
        }

        return result;
    }
};