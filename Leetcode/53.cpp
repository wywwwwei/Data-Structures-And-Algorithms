/**
 * 53. 最大子序和 Kadane实质为动态规划
 * link：https://leetcode-cn.com/problems/maximum-subarray/
 */

/**
 * In fact, I wrote this question directly according to the law
 * - If it is a mixture of positive and negative numbers, 
 *   when the sum of n consecutive numbers is less than 0, 
 *   then these n numbers will definitely not be included in the answer, 
 *   so when this happens, it will be recalculated directly from the current position, 
 *   but the answer may be included in these n numbers, 
 *   we need to record the maximum value for each traversal.
 * 
 *   If they are all negative, it is equivalent to traversing the maximum value using max comparison
 *   If they are all positive, the answer is the sum of the sequence values
 */
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int max_val = INT_MIN;
        for (const int &num : nums)
        {
            sum += num;
            max_val = max(sum, max_val);
            if (sum < 0 && sum != INT_MIN)
                sum = 0;
        }
        return max_val;
    }
};