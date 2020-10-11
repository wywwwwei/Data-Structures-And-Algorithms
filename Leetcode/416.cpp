/**
 * 416. 分割等和子集 dp
 * link：https://leetcode-cn.com/problems/partition-equal-subset-sum/
 */

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return false;

        int max_n = INT_MIN;
        int sum = 0;
        for (const int &num : nums)
        {
            sum += num;
            max_n = max(max_n, num);
        }

        int target = sum / 2;
        if (sum % 2 == 1 || max_n > target)
            return false;

        // int cap = sum / 2 + 1;
        // vector<bool> dp(cap, false);
        // dp[0] = true;
        // dp[nums[0]] = true;
        // for (int i = 1; i < n; i++)
        //     for (int j = cap - 1; j >= nums[i]; j--)
        //         dp[j] = dp[j] | dp[j - nums[i]];
        // return dp[cap - 1];

        // Optimized
        bitset<10001> bits(1);
        for (const int &num : nums)
            bits |= bits << num;
        return bits[target];
    }
};