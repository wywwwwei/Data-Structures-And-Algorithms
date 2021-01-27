/**
 * 1579. 保证图可完全遍历
 * link：https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
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
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto &edge : edges)
        {
            --edge[1];
            --edge[2];
        }

        int countAlice = n;
        int result = 0;
        for (const auto &edge : edges)
        {
            if (edge[0] == 3)
            {
                if (merge(parent, edge[1], edge[2]))
                    --countAlice;
                else
                    ++result;
            }
        }

        int countBob = countAlice;
        vector<int> parentBob(parent);
        for (const auto &edge : edges)
        {
            if (edge[0] == 1)
            {
                // Alice
                if (merge(parent, edge[1], edge[2]))
                    --countAlice;
                else
                    ++result;
            }
            else if (edge[0] == 2)
            {
                // Bob
                if (merge(parentBob, edge[1], edge[2]))
                    --countBob;
                else
                    ++result;
            }
        }

        if (countAlice != 1 || countBob != 1)
            return -1;
        return result;
    }
};