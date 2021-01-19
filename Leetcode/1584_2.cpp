/**
 * 1584. 连接所有点的最小费用   Prim
 * link：https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
 */

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        auto distance = [&points](const int x, const int y) {
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };

        int n = points.size();

        vector<int> dist(n);
        vector<bool> mst(n, false);
        int result = 0;

        mst[0] = true;
        for (int i = 0; i < n; i++)
            dist[i] = distance(0, i);

        for (int i = 0; i < n - 1; i++)
        {
            // find minimum vertex
            int minKey = -1;
            for (int j = 0; j < n; j++)
                if (!mst[j] && (minKey == -1 || dist[j] < dist[minKey]))
                    minKey = j;
            // add
            result += dist[minKey];
            mst[minKey] = true;

            // update
            for (int j = 0; j < n; j++)
                dist[j] = min(dist[j], distance(minKey, j));
        }

        return result;
    }
};