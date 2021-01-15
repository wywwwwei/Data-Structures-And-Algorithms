/**
 * 947. 移除最多的同行或同列石头
 * link：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
 */

/**
 * result = the number of stones - the number of connected components
 * we use union-find to record the component
 * 2d coordinates -> 1d index: merge x + 10001 and y because 0 <= x,y <= 10000
 */

class Solution
{
    int count = 0;

    void merge(unordered_map<int, int> &parent, int x, int y)
    {
        int parent_x = findParent(parent, x);
        int parent_y = findParent(parent, y);

        if (parent_x == parent_y)
            return;
        parent[parent_x] = parent_y;
        --count;
    }

    int findParent(unordered_map<int, int> &parent, int x)
    {
        if (parent.find(x) == parent.end())
        {
            parent[x] = x;
            ++count;
        }
        if (parent[x] != x)
            parent[x] = findParent(parent, parent[x]);
        return parent[x];
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, int> parent;

        for (const auto &stone : stones)
            merge(parent, stone[0] + 10001, stone[1]);

        return n - count;
    }
};