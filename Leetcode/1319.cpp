/**
 * 1319. 连通网络的操作次数
 * link：https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
 */

class Solution
{
    int setCount;

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
        --setCount;
        return true;
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // int unusedLine = 0;
        // for (const auto &connection : connections)
        //     if (!merge(parent, connection[0], connection[1]))
        //         unusedLine++;

        // int notConnect = 0;
        // for (int i = 0; i < n; i++)
        //     if (parent[i] == i)
        //         notConnect++;

        // return notConnect - 1 <= unusedLine ? notConnect - 1 : -1;

        setCount = n;
        for (const auto &connection : connections)
            merge(parent, connection[0], connection[1]);
        return setCount - 1;
    }
};