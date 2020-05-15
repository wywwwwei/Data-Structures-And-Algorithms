/**
 * 560. 和为K的子数组
 * link：https://leetcode-cn.com/problems/subarray-sum-equals-k/
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