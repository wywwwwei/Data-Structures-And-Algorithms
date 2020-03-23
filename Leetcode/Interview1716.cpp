/**
 * 面试题 17.16. 按摩师 动态规划
 * link：https://leetcode-cn.com/problems/the-masseuse-lcci/
 */

class Solution
{
public:
    int massage(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return 0;

        vector<int> dp(nums.size() + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        return dp[nums.size()];
    }
};