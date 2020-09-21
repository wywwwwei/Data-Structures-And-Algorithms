/**
 * 1486. 数组异或操作 模拟
 * link：https://leetcode-cn.com/problems/xor-operation-in-an-array/
 */

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int result = 0;
        int cur = start;
        while (n-- > 0)
        {
            result ^= cur;
            cur += 2;
        }
        return result;
    }
};