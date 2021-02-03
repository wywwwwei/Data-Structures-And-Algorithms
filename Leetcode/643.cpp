/**
 * 643. 子数组最大平均数 I
 * link：https://leetcode-cn.com/problems/maximum-average-subarray-i/
 */

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int n = nums.size();
        double result = 1.0 * sum / k;

        for (int i = k; i < n; i++)
        {
            sum -= nums[i - k];
            sum += nums[i];
            result = max(result, 1.0 * sum / k);
        }

        return result;
    }
};