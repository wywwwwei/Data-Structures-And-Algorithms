/**
 * 839. 相似字符串组
 * link：https://leetcode-cn.com/problems/similar-string-groups/
 */

class Solution
{
    int findParent(vector<int> &parent, int x)
    {
        return parent[x] == x ? x : parent[x] = findParent(parent, parent[x]);
    }

    bool similar(string &a, string &b)
    {
        int n = a.length();
        int diff = 0; // anagram. Similar when diff = 2
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (++diff > 2)
                    return false;
            }
        }
        return true;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();

        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (findParent(parent, i) == findParent(parent, j))
                    continue;
                if (similar(strs[i], strs[j]))
                    parent[parent[i]] = parent[j];
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                result++;

        return result;
    }
};