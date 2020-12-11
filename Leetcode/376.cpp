/**
 * 376. 摆动序列    greedy
 * link：https://leetcode-cn.com/problems/wiggle-subsequence/
 */

/**
 * Consider the current position i, 
 * 1. nums[i] < nums[i+1]
 *      1.1 nums[i+1] < nums[i+2]   len no change
 *      1.2 nums[i+1] > nums[i+2]   len + 1
 * 2. nums[i] > nums[i+1]
 *      2.1 nums[i+1] > nums[i+2]   len no change
 *      2.2 nums[i+1] < nums[i+2]   len + 1 
 * 
 */

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = unique(nums.begin(), nums.end()) - nums.begin();
        if (n <= 2)
            return n;

        int prev_diff = nums[1] - nums[0];
        int result = 2;
        for (int i = 2; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if ((prev_diff < 0 && diff > 0) || (prev_diff > 0 && diff < 0))
            {
                result++;
                prev_diff = diff;
            }
        }

        return result;
    }
};