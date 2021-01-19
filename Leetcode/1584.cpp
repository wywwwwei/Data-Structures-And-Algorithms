/**
 * 1584. 连接所有点的最小费用   Kruskal
 * link：https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
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

    struct Edge
    {
        int dist;
        int x;
        int y;
        Edge(int dist, int x, int y) : dist(dist), x(x), y(y) {}
    };

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        auto distance = [&points](const int x, const int y) -> int {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };

        int n = points.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        vector<Edge> edges;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edges.emplace_back(distance(i, j), i, j);

        sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) -> bool { return a.dist < b.dist; });
        int result = 0;
        int count = 0;
        for (const auto &edge : edges)
        {
            if (findParent(parent, edge.x) != findParent(parent, edge.y))
            {
                merge(parent, edge.x, edge.y);
                result += edge.dist;
                if (++count == n)
                    break;
            }
        }

        return result;
    }
};