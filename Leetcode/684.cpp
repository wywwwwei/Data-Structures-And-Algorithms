/**
 * 684. 冗余连接 并查集
 * link：https://leetcode-cn.com/problems/redundant-connection/
 */

class Solution
{
    vector<int> ancestor;

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        ancestor.resize(n + 1, 0);
        iota(ancestor.begin() + 1, ancestor.end(), 1);

        int result;
        for (int i = 0; i < n; i++)
        {
            if (find(edges[i][0]) == find(edges[i][1]))
                result = i;
            else
                merge(edges[i][0], edges[i][1]);
        }
        return edges[result];
    }

    int find(int index)
    {
        return ancestor[index] == index ? index : find(ancestor[index]);
    }

    void merge(int u, int v)
    {
        int a = find(u);
        int b = find(v);
        if (a <= b)
            ancestor[b] = a;
        else
            ancestor[a] = b;
    }
};