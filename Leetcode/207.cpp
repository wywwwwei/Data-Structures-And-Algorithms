/**
 * 207. 课程表 topological sort
 * link：https://leetcode-cn.com/problems/course-schedule/
 */

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<list<int>> adjacent(numCourses);
        vector<int> indgree(numCourses);

        for (auto &prerequisite : prerequisites)
        {
            adjacent[prerequisite[1]].push_back(prerequisite[0]);
            indgree[prerequisite[0]]++;
        }

        queue<int> indgree_zero;
        for (int i = 0; i < numCourses; i++)
            if (indgree[i] == 0)
                indgree_zero.push(i);

        while (!indgree_zero.empty())
        {
            int temp = indgree_zero.front();
            indgree_zero.pop();
            for (auto &t : adjacent[temp])
            {
                indgree[t]--;
                if (indgree[t] == 0)
                    indgree_zero.push(t);
            }
            numCourses--;
        }

        return numCourses == 0;
    }
};