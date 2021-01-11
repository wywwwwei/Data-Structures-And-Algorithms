/**
 * 1202. 交换字符串中的元素 Union-find
 * link：https://leetcode-cn.com/problems/smallest-string-with-swaps/
 */

class Solution
{
    int findParent(vector<int>& parent, int index)
    {
        if (parent[index] != index)
            parent[index] = findParent(parent, parent[index]);
        return parent[index];
    }

    void merge(vector<int>& parent, int a, int b)
    {
        int parent_a = findParent(parent, a);
        int parent_b = findParent(parent, b);
        parent[parent_a] = parent_b;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto &pair : pairs)
            merge(parent, pair[0], pair[1]);

        unordered_map<int, vector<char>> can_swap;
        for (int i = 0; i < n; i++)
            can_swap[findParent(parent, i)].emplace_back(s[i]);

        for (auto &kv : can_swap)
            sort(kv.second.begin(), kv.second.end(), greater<char>());

        for (int i = 0; i < n; i++)
        {
            int x = findParent(parent, i);
            s[i] = can_swap[x].back();
            can_swap[x].pop_back();
        }

        return s;
    }
};