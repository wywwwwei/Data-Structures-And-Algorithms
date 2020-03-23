/**
 * 198. 打家劫舍 动态规划->遍历 同Interview1716 
 * link：https://leetcode-cn.com/problems/house-robber/
 */

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int pre = 0;
        int cur = 0;

        for (int &num : nums)
        {
            int temp = cur;
            cur = max(cur, pre + num);
            pre = temp;
        }

        return cur;
    }
};
