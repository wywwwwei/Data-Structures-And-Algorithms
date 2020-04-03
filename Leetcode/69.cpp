/**
 * 69. x 的平方根
 * link：https://leetcode-cn.com/problems/sqrtx/
 */

/**
 * 1.brute force
 * 2.binary search
 * 3.recursive  sqrt(x) = 2 * sqrt(x/4)
 * 4.Newton's method
 */

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        double x0 = x;
        double x1 = (x0 + x / x0) / 2;
        while (fabs(x0 - x1) >= 1)
        {
            x0 = x1;
            x1 = (x0 + x / x0) / 2;
        }

        return (int)x1;
    }
};