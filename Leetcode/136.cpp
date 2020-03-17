/**
 * 136. 只出现一次的数字 xor两数抵消
 * link：https://leetcode-cn.com/problems/single-number/
 */

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int res = 0;
        for (auto num : nums)
        {
            res = res ^ num;
        }
        return res;
    }
};