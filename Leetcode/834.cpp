/**
 * 834. 树中距离之和
 * link：https://leetcode-cn.com/problems/sum-of-distances-in-tree/
 */

/**
 * Assume that node A and node B are connected, and so they're children of each other
 * For each node, consider the subtree S(node) of that node plus all descendants.
 * count(node) is the number of nodes in S(node)
 * sum(node) is the sum of the distances from node to the nodes in S(node)
 * 
 * ans(A) = sum(A) + sum(B) + count(B)
 * ans(B) = sum(B) + sum(A) + count(A)
 * 
 * So the state transfer equation is
 * ans(A) - ans(B) = count(B) - count(A) = count(B) - (N - count(B)) = 2 * count(B) - N
 * ans(A) = ans(B) + 2 * count(B) - N
 */

class Solution
{
    vector<int> dp;
    vector<int> count;
    vector<vector<int>> graph;
    int n;

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        n = N;
        dp.resize(N, 0);
        count.resize(N, 1);
        graph.resize(N, vector<int>());

        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        getCountDfs(-1, 0);
        dfs(-1, 0);

        return dp;
    }

    void getCountDfs(int parent, int child)
    {
        for (int i = 0; i < graph[child].size(); i++)
        {
            if (graph[child][i] != parent)
            {
                getCountDfs(child, graph[child][i]);
                count[child] += count[graph[child][i]];
                dp[child] += count[graph[child][i]] + dp[graph[child][i]];
            }
        }
    }

    void dfs(int parent, int child)
    {
        for (int i = 0; i < graph[child].size(); i++)
        {
            if (graph[child][i] != parent)
            {
                dp[graph[child][i]] = dp[child] - count[graph[child][i]] * 2 + n;
                dfs(child, graph[child][i]);
            }
        }
    }
};