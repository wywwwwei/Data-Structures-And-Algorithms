/**
 * 485. 最大连续1的个数
 * link：https://leetcode-cn.com/problems/max-consecutive-ones/
 */

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();

        int result = 0;
        // int left = 0, right = 0;
        // while (right < n)
        // {
        //     while (right < n && nums[right] == 1)
        //         ++right;
        //     result = max(result, right - left);
        //     while (right < n && nums[right] == 0)
        //         ++right;
        //     left = right;
        // }
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                ++cur;
            }
            else
            {
                result = max(result, cur);
                cur = 0;
            }
        }
        result = max(result, cur);

        return result;
    }
};