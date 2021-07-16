/**
 * 剑指 Offer 42. 连续子数组的最大和
 * link：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
 */

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = nums[0];
        int last = 0;

        for (int num : nums)
        {
            last = max(last + num, num);
            result = max(result, last);
        }

        return result;
    }
};