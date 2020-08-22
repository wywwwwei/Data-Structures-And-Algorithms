/**
 * 201. 数字范围按位与  the common prefix of binary numbers
 * link：https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/
 */

/**
 * The purpose of this question is to find the common prefix of the corresponding binary string,
 * because if you have different values in the same bit, then that bit in result must be zero.
 * 
 * Brian Kernighan's Algorithm
 */

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        while (m < n)
            n &= (n - 1);

        return n;
    }
};