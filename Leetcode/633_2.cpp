/**
 * 633. 平方数之和 枚举
 * link：https://leetcode-cn.com/problems/sum-of-square-numbers/
 */

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int max = (int)sqrt(c);
        for (int i = 0; i <= max; i++)
        {
            double res = sqrt(c - i * i);
            if (res == (int)res)
            {
                return true;
            }
        }
        return false;
    }
};