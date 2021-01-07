/**
 * 547. 省份数量    dfs
 * link：https://leetcode-cn.com/problems/number-of-provinces/
 */

class Solution
{
    vector<bool> visit;
    void dfs(vector<vector<int>> &graph, int i)
    {
        int n = graph.size();
        visit[i] = true;
        for (int j = 0; j < n; j++)
        {
            if (!visit[j] && graph[i][j] == 1)
                dfs(graph, j);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        visit.resize(n, false);

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                dfs(isConnected, i);
                result++;
            }
        }

        return result;
    }
};