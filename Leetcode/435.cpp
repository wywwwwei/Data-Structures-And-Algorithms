/**
 * 435. 无重叠区间
 * link：https://leetcode-cn.com/problems/non-overlapping-intervals/
 */

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n <= 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[1] < b[1];
        });

        int curEnd = intervals[0][1];
        int result = 1;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= curEnd)
            {
                result++;
                curEnd = intervals[i][1];
            }
        }

        return n - result;
    }
};