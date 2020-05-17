/**
 * 210. 课程表 II topological sort
 * link：https://leetcode-cn.com/problems/course-schedule-ii/
 */

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, list<int>> graph;
        vector<int> indegrees(numCourses, 0);

        //construct adjacency table
        for (auto &pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            indegrees[pre[0]]++;
        }


        //BFS
        queue<int> topo;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)
                topo.push(i);
        }

        vector<int> result;
        while (!topo.empty())
        {
            int cur = topo.front();
            topo.pop();
            result.push_back(cur);
            for (auto &out : graph[cur])
            {
                indegrees[out]--;
                if (indegrees[out] == 0)
                    topo.push(out);
            }
        }

        return (result.size() == numCourses ? result : vector<int>());
    }
};