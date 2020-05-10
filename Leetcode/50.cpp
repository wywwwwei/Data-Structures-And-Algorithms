/**
 * 50. Pow(x, n)
 * link：https://leetcode-cn.com/problems/powx-n/
 */

/**
 * if n >= 0
 *      if n is an even number, x ^ n = (x ^ n/2) ^ 2
 *      if n is an odd number, x ^ n = (x ^ n/2) ^ 2 * x
 * So it can be expressed as ((((x ^ 1) ^ 2 * kx) ^ 2 * kx) ^ 2 * kx)..., each k may be 0 or 1  
 * We can find that in addition to x ^ (2 / 4 / 8 / 16...), each kx needs to be record 
 * and its value is kx ^ (the power of 2 nested in the outer layer)
 * So we can do x = x * 2 in each loop, when k = 1, result = result * x, 
 * and finally when n = 1, do result = result * x to record x ^ (2 / 4 / 8 / 16...)
 */

class Solution
{
public:
    double myPow(double x, int n)
    {
        double result = 1.0;
        for (int i = n; i != 0; i /= 2)
        {
            if (i % 2)
                result *= x;
            x *= x;
        }
        return n > 0 ? result : 1 / result;
    }
};