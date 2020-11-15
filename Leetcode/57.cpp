/**
 * 57. 插入区间
 * link：https://leetcode-cn.com/problems/insert-interval/
 */

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> result;
        int left = newInterval[0];
        int right = newInterval[1];
        bool find = false;
        for (const auto &interval : intervals)
        {
            if (interval[0] > right)
            {
                if (!find)
                {
                    find = true;
                    result.push_back({left, right});
                }
                result.push_back(interval);
            }
            else if (interval[1] < left)
            {
                result.push_back(interval);
            }
            else
            {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!find)
            result.push_back({left, right});
        return result;
    }
};