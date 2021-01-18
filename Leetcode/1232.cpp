/**
 * 1232. 缀点成线
 * link：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
 */

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int n = coordinates.size();
        int curdx = 0, curdy = 0;
        int lastdx = coordinates[1][0] - coordinates[0][0];
        int lastdy = coordinates[1][1] - coordinates[0][1];
        for (int i = 2; i < n; i++)
        {
            curdx = coordinates[i][0] - coordinates[i - 1][0];
            curdy = coordinates[i][1] - coordinates[i - 1][1];
            if (curdx * lastdy != curdy * lastdx)
                return false;
            lastdx = curdx;
            lastdy = curdy;
        }
        return true;
    }
};