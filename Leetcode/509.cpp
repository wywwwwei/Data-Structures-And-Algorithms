/**
 * 509. 斐波那契数
 * link：https://leetcode-cn.com/problems/fibonacci-number/
 */

#define MOD 1000000007

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        int n0 = 0, n1 = 1;
        int result = 0;
        while (n-- > 1)
        {
            result = (n0 + n1) % MOD;
            n0 = n1;
            n1 = result;
        }
        return result;
    }
};