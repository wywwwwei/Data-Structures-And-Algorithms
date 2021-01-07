/**
 * 547. 省份数量    Union-find
 * link：https://leetcode-cn.com/problems/number-of-provinces/
 */

class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        if (parent[x] != x)
            parent[x] = findParent(parent, parent[x]);
        return parent[x];
    }

    void merge(vector<int> &parent, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        parent[parent_a] = parent_b;
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j] == 1)
                    merge(parent, i, j);

        int result = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                result++;

        return result;
    }
};