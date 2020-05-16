/**
 * 560. 和为K的子数组
 * link：https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

/**
 * Denote the sum of values from nums[0] to nums[x] as sum(x)
 * To find sum(i) - sum(j) = k    (i > j)
 * sum(j) = sum(i) - k
 * Traverse and calculate each sum, if sum(i) - k exists, then the sum of subarray from j + 1 to i exists 
 */

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        int sum = 0;
        int result = 0;
        record[sum] = 1;

        for (auto &num : nums)
        {
            sum += num;
            if (record.find(sum - k) != record.end())
                result += record[sum - k];
            record[sum]++;
        }

        return result;
    }
};