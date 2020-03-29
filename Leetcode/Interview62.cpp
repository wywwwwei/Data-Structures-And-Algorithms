/**
 * 面试题62. 圆圈中最后剩下的数字
 * link：https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
 */

/**
 * Josephus Circle
 * f(n) = (f(n-1, m) + m) % n
 */
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        int result = 0;

        for (int i = 2; i <= n; i++)
        {
            result = (result + m) % i;
        }

        return result;
    }
};