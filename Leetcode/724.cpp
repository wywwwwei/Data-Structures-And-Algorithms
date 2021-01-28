/**
 * 724. 寻找数组的中心索引
 * link：https://leetcode-cn.com/problems/find-pivot-index/
 */

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (cur * 2 + nums[i] == sum)
                return i;
            cur += nums[i];
        }

        return -1;
    }
};