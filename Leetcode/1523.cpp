/**
 * 1523. 在区间范围内统计奇数数目
 * link：https://leetcode-cn.com/problems/count-odd-numbers-in-an-interval-range/
 */

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int count = high - low + 1;
        if (count % 2)
        {
            if (low % 2)
                return count / 2 + 1;
        }
        return count / 2;
    }
};