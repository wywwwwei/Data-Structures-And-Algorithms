/**
 * 207. 课程表 dfs
 * link：https://leetcode-cn.com/problems/course-schedule/
 */

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<list<int>> adjacent(numCourses);
        vector<char> flag(numCourses);

        for (auto prerequisite : prerequisites)
        {
            adjacent[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++)
            if (!dfs(adjacent, flag, i))
                return false;

        return true;
    }

    bool dfs(vector<list<int>> &adjacent, vector<char> &flag, int node)
    {
        if (flag[node] == 1)
            return false;
        if (flag[node] == 2)
            return true;

        flag[node] = 1;
        for (auto &next : adjacent[node])
            if (!dfs(adjacent, flag, next))
                return false;

        flag[node] = 2;
        return true;
    }
};