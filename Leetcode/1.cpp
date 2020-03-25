/**
 * 1. 两数之和
 * link：https://leetcode-cn.com/problems/two-sum/
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;

        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(target - nums[i]) != record.end())
                return {record[target - nums[i]], i};
            record[nums[i]] = i;
        }

        return {};
    }
};