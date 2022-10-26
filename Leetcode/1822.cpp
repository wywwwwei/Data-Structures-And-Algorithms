/**
 * 1822. 数组元素积的符号
 * link：https://leetcode.cn/problems/sign-of-the-product-of-an-array/
 */

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        bool positive = true;
        for (const int num : nums)
        {
            if (num == 0)
            {
                return 0;
            }
            if (num < 0)
            {
                positive = !positive;
            }
        }
        return positive ? 1 : -1;
    }
};