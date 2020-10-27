/**
 * 1207. 独一无二的出现次数
 * link：https://leetcode-cn.com/problems/unique-number-of-occurrences/
 */

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> nums;
        for (const int &a : arr)
            nums[a]++;

        unordered_set<int> times;
        for (const auto &num : nums)
            times.insert(num.second);

        return times.size() == nums.size();
    }
};