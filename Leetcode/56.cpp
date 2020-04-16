/**
 * 56. 合并区间
 * link：https://leetcode-cn.com/problems/merge-intervals/
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 0)
            return {};

        vector<vector<int>> result;
        auto cmp = [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        result.push_back(intervals.back());
        return result;
    }
};