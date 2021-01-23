/**
 * 674. 最长连续递增序列
 * link：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return 0;

        int cur = 1;
        int result = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ++cur;
            }
            else
            {
                result = max(result, cur);
                cur = 1;
            }
        }

        return max(result, cur);
    }
};
