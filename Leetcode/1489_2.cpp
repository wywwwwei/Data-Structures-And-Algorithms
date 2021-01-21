/**
 * 1489. 找到最小生成树里的关键边和伪关键边   Tarjan's Algorithm
 * link：https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
 */

/**
 * Tarjan's algorithm used to find the bridge/cut point of a undirected graph
 * https://qoogle.top/tarjan-algorithm-and-cut-points-and-bridges-for-undirected-graphs/
 */

/**
 * We first sort edges by weight from smallest to largest
 * and find bridge edge for the edges whose weight are same in ascending order
 * For a edge whose weight is w connect component a and component b
 *      1. there is already a edge whose weight <w connect a and b  ->  a and b is already a component, self-cycle 
 *      2. firstly and only connect a and b  ->  bridge edge  ->  critical edge
 *      3. other edges whose weight are w connect a and b   ->  pseudo-critical edge
 * 
 */
class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : findParent(parent, parent[x]);
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

    void dfs(vector<int> &result, vector<vector<int>> &graph, vector<vector<int>> &graph2id, vector<int> &discover, vector<int> &low, int &times, int cur, int parentEdge)
    {
        discover[cur] = low[cur] = times++;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int connNode = graph[cur][i];
            int id = graph2id[cur][i];
            if (discover[connNode] == -1)
            {
                dfs(result, graph, graph2id, discover, low, times, connNode, id);
                low[cur] = min(low[cur], low[connNode]);
                if (low[connNode] > discover[cur])
                    result.emplace_back(id);
            }
            else if (id != parentEdge)
            {
                low[cur] = min(low[cur], discover[connNode]);
            }
        }
    };
    vector<int> tarjan(vector<vector<int>> &graph, vector<vector<int>> &graph2id)
    {
        int n = graph.size();

        vector<int> low(n, -1);
        vector<int> discover(n, -1);

        int times = 0;
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (discover[i] == -1)
                dfs(result, graph, graph2id, discover, low, times, i, -1);
        return result;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        for (int i = 0; i < m; i++)
            edges[i].emplace_back(i);

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[2] < b[2];
        });

        vector<int> critical;
        vector<int> pseudoCritical;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        vector<bool> edgeLabel(m, false);
        for (int i = 0; i < m;)
        {
            int w = edges[i][2];
            int j = i;
            while (j < m && edges[j][2] == w)
                ++j;

            unordered_map<int, int> comp2id;
            int nodes = 0;
            for (int k = i; k < j; k++)
            {
                int x = findParent(parent, edges[k][0]);
                int y = findParent(parent, edges[k][1]);
                if (x != y)
                {
                    if (comp2id.find(x) == comp2id.end())
                        comp2id[x] = nodes++;
                    if (comp2id.find(y) == comp2id.end())
                        comp2id[y] = nodes++;
                }
                else
                {
                    edgeLabel[edges[k][3]] = true;
                }
            }

            vector<vector<int>> graph(nodes);
            vector<vector<int>> graph2id(nodes);
            for (int k = i; k < j; k++)
            {
                int x = findParent(parent, edges[k][0]);
                int y = findParent(parent, edges[k][1]);
                if (x != y)
                {
                    int idx = comp2id[x], idy = comp2id[y];
                    graph[idx].emplace_back(idy);
                    graph[idy].emplace_back(idx);
                    graph2id[idx].emplace_back(edges[k][3]);
                    graph2id[idy].emplace_back(edges[k][3]);
                }
            }

            vector<int> bridges(tarjan(graph, graph2id));
            for (int id : bridges)
            {
                critical.emplace_back(id);
                edgeLabel[id] = true;
            }

            for (int k = i; k < j; k++)
                merge(parent, edges[k][0], edges[k][1]);

            i = j;
        }

        for (int i = 0; i < m; i++)
            if (!edgeLabel[i])
                pseudoCritical.emplace_back(i);

        return {critical, pseudoCritical};
    }
};