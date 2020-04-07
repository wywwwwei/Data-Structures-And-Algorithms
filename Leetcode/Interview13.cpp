/**
 * 面试题13. 机器人的运动范围
 * link：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 */

/**
 * We can optimize the search to only right and down
 * As k increases, the grid area the row and column coordinates satisfying 
 * the sum of the each digit of them is greater than k 
 * will only move to the right or down, further connecting to form a larger area
 */

class Solution
{
    int getSum(int x)
    {
        int result = 0;
        while (x > 0)
        {
            result += x % 10;
            x /= 10;
        }
        return result;
    }

public:
    int movingCount(int m, int n, int k)
    {
        if (k <= 0)
            return 1;
        vector<vector<bool>> visitable(m, vector<bool>(n, false));

        int result = 0;
        visitable[0][0] = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (getSum(i) + getSum(j) > k)
                    continue;
                if (i > 0)
                    visitable[i][j] = visitable[i][j] || visitable[i - 1][j];
                if (j > 0)
                    visitable[i][j] = visitable[i][j] || visitable[i][j - 1];
                if (visitable[i][j])
                    result += 1;
            }
        }
        return result;
    }
};