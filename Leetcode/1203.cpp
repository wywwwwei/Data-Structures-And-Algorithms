/**
 * 1203. 项目管理   topological sorting
 * link：https://leetcode-cn.com/problems/sort-items-by-groups-respecting-dependencies/
 */

class Solution
{
    vector<int> topSort(vector<vector<int>> &graph, vector<int> &degree, vector<int> &toSort)
    {
        int n = toSort.size();

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[toSort[i]] == 0)
                q.push(toSort[i]);

        vector<int> result;
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            result.emplace_back(tmp);
            for (auto x : graph[tmp])
            {
                if (--degree[x] == 0)
                    q.push(x);
            }
        }

        return result.size() != n ? vector<int>{} : result;
    }

public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems)
    {
        // preprocess
        for (int i = 0; i < n; i++)
            if (group[i] == -1)
                group[i] = m++;

        // graph and degree
        vector<vector<int>> groupGraph(m);
        vector<vector<int>> itemGraph(n);
        vector<int> groupDegree(m, 0);
        vector<int> itemDegree(n, 0);
        vector<vector<int>> groupItem(m);

        for (int i = 0; i < n; i++)
        {
            int curGroup = group[i];
            groupItem[curGroup].emplace_back(i);
            for (auto x : beforeItems[i])
            {
                int beforeGroup = group[x];
                if (curGroup != beforeGroup)
                {
                    groupGraph[beforeGroup].emplace_back(curGroup);
                    groupDegree[curGroup]++;
                }
                else
                {
                    itemGraph[x].emplace_back(i);
                    itemDegree[i]++;
                }
            }
        }

        // group top sort
        vector<int> allGroup(m);
        iota(allGroup.begin(), allGroup.end(), 0);
        vector<int> groupTopSort = topSort(groupGraph, groupDegree, allGroup);
        if (groupTopSort.empty())
            return {};

        // item top sort
        vector<int> result;
        for (auto curGroup : groupTopSort)
        {
            auto &items = groupItem[curGroup];
            if (items.empty())
                continue;
            vector<int> tmp = topSort(itemGraph, itemDegree, groupItem[curGroup]);
            if (tmp.empty())
                return {};
            for (auto x : tmp)
                result.emplace_back(x);
        }

        return result;
    }
};