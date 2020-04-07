/**
 * 746. 使用最小花费爬楼梯 dp
 * link：https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 */

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int f_1 = 0;
        int f_2 = 0;
        for (int i = 0; i < cost.size(); i++)
        {
            int temp = min(f_1, f_2) + cost[i];
            f_1 = f_2;
            f_2 = temp;
        }

        return min(f_1, f_2);
    }
};