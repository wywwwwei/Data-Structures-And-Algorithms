/**
 * 1489. 找到最小生成树里的关键边和伪关键边   Kruskal
 * link：https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
 */

/**
 * Critical: the edge that can appear in all MSTs
 * so after deleting it, the graph is not connected or the MST weight will increase 
 * 
 * Pseudo-Critical: the edge that can appear in some MSTs but not all
 * the weight of the MST that contains pseudo-critical edge is equal to the original MST weight
 * 
 * They are mutually exclusive
 */
class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : findParent(parent, parent[x]);
    }

    bool merge(vector<int> &parent, int &count, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        if (parent_a == parent_b)
            return false;
        parent[parent_a] = parent_b;
        --count;
        return true;
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

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        int mstVal = 0;
        int count = n;
        for (int i = 0; i < m; ++i)
            if (merge(parent, count, edges[i][0], edges[i][1]))
                mstVal += edges[i][2];

        vector<int> key;
        vector<int> fakeKey;
        for (int i = 0; i < m; ++i)
        {
            // init
            count = n;
            iota(parent.begin(), parent.end(), 0);
            int curMst = 0;
            // kruskal
            for (int j = 0; j < m; j++)
                if (i != j && merge(parent, count, edges[j][0], edges[j][1]))
                    curMst += edges[j][2];
            if (count != 1 || (count == 1 && curMst > mstVal))
            {
                key.emplace_back(edges[i][3]);
                continue;
            }

            // init
            count = n;
            iota(parent.begin(), parent.end(), 0);
            merge(parent, count, edges[i][0], edges[i][1]);
            curMst = edges[i][2];
            // kruskal
            for (int j = 0; j < m; j++)
                if (i != j && merge(parent, count, edges[j][0], edges[j][1]))
                    curMst += edges[j][2];
            if (curMst == mstVal)
                fakeKey.emplace_back(edges[i][3]);
        }

        return {key, fakeKey};
    }
};
