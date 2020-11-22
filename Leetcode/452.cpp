/**
 * 452. 用最少数量的箭引爆气球
 * link：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 0)
            return 0;

        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[1] < b[1];
        });

        int result = 1;
        int max_dis = points[0][1];

        for (const auto &point : points)
        {
            if (point[0] > max_dis)
            {
                result++;
                max_dis = point[1];
            }
        }

        return result;
    }
};