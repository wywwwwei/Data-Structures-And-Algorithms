/**
 * 633. 平方数之和 双指针
 * link：https://leetcode-cn.com/problems/sum-of-square-numbers/
 */
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int index1 = 0;
        int index2 = (int)sqrt(c);
        while (index1 <= index2)
        {
            // Forgot to consider the case of overflow
            //
            // int square_sum = index1 * index1 + index2 * index2;
            // if (square_sum < c)
            // {
            //     index1++;
            // }
            // else if (square_sum > c)
            // {
            //     index2--;
            // }
            // else
            // {
            //     return true;
            // }
            if (index1 * index1 < c - index2 * index2)
            {
                index1++;
            }
            else if (index1 * index1 > c - index2 * index2)
            {
                index2--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};