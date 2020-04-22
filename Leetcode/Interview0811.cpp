/**
 * 面试题 08.11. 硬币
 * link：https://leetcode-cn.com/problems/coin-lcci/
 */

/**
 * Traverse (x = 0 ~ n / 25) coins with a face value of 25 and (r = n - 25 * x) remaining
 * Suppose we use (y = 0 ~ r / 10) coin with a face value of 10 (a0 = r / 10  b0 = r % 10 / 5 c0 = r - 10 * a0 - 5 * b0)
 * Then the rest can be expressed as 10(a0 - y) + 5b0 + c0 = 5(2a0 + b0 - 2y) + c0
 * So we can use (z = 0 ~ 2a0 + b0) coin with a face value of 5 and the rest are coins with a face value of 1
 * 
 * Sum y [0 , a0], it is (a0 + 1) * (a0 + b0 + 1)
 */
class Solution
{
public:
    int waysToChange(int n)
    {
        const int mod = 1000000007;

        int result = 0;
        for (int i = 0; i * 25 <= n; i++)
        {
            int rest = n - i * 25;
            int a = rest / 10;
            int b = rest % 10 / 5;
            result = (result + (long long)(a + 1) * (a + b + 1) % mod) % mod;
        }

        return result;
    }
};