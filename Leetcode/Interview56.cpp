/**
 * 面试题56 - I. 数组中数字出现的次数
 * link：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int result = 0;
        for (auto &num : nums)
            result ^= num;
        result = result & (-result);

        int res1 = 0;
        int res2 = 0;
        for (auto &num : nums)
        {
            if (num & result)
                res1 ^= num;
            else
                res2 ^= num;
        }

        return {res1, res2};
    }
};