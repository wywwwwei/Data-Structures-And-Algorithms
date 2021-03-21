/**
 * 191. 位1的个数
 * link：https://leetcode-cn.com/problems/number-of-1-bits/
 */

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n > 0)
        {
            n &= (n - 1);
            ++result;
        }
        return result;
        
        // return bitset<32>(n).count();
    }
};