/**
 * 621. 任务调度器
 * link：https://leetcode-cn.com/problems/task-scheduler/
 */

/**
 * It is not hard to see that the shortest completion time depends on the most tasks
 * assume that only task A comes up the most and all other tasks can be set into X
 * A -> 1th X -> ... -> nth X -> A -> 1th X -> ... -> nth X -> A ... -> the last A
 * time = (count(A) - 1) * (n + 1) + 1
 * if not only task A comes up the most
 * time = (count(A) - 1) * (n + 1) + the number of count equals to count(A)
 * 
 * However, there is no guarantee that sum of count not equals to count(A) always less than (count(A) - 1) * n
 * at that time, we need to insert the additional task directly (because the period between two same tasks must > n ) = size of tasks
 * 
 * so the result is max((count(A) - 1) * (n + 1) + the number of count equals to count(A), size of tasks)
 */

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int count[26] = {0};
        for (const char &task : tasks)
            count[task - 'A']++;

        sort(count, count + 26);
        int max_freq = 1;
        for (int i = 24; i >= 0 && count[i] == count[i + 1]; i--)
            max_freq++;

        return max((int)tasks.size(), (count[25] - 1) * (n + 1) + max_freq);
    }
};