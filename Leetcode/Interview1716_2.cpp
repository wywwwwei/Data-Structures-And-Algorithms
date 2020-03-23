/**
 * 面试题 17.16. 按摩师 动态规划->遍历
 * link：https://leetcode-cn.com/problems/the-masseuse-lcci/
 */

class Solution
{
public:
    int massage(vector<int> &nums)
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