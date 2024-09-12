/**
 * 2398. 预算内的最多机器人数目 Maximum number of robots within budget
 * link：https://leetcode.cn/problems/maximum-number-of-robots-within-budget/
 */

#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        int result = 0;
        long long costSum = 0;

        deque<int> maxChargeTimes;
        for (int i = 0, j = 0; j < n; ++j)
        {
            costSum += runningCosts[j];
            while (!maxChargeTimes.empty() && chargeTimes[maxChargeTimes.back()] <= chargeTimes[j])
            {
                maxChargeTimes.pop_back();
            }
            maxChargeTimes.push_back(j);
            while (i <= j && (j - i + 1) * costSum + chargeTimes[maxChargeTimes.front()] > budget)
            {
                if (!maxChargeTimes.empty() && maxChargeTimes.front() == i)
                {
                    maxChargeTimes.pop_front();
                }
                costSum -= runningCosts[i];
                ++i;
            }
            result = max(result, j - i + 1);
        }

        return result;
    }
};