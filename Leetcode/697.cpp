/**
 * 697. 数组的度
 * link：https://leetcode-cn.com/problems/degree-of-an-array/
 */

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        // record index of first occurrence and the number of occurrences
        unordered_map<int, pair<int, int>> record;

        int n = nums.size();
        int max_times = 1;
        int result = INT_MAX;

        for (int i = 0; i < n; ++i)
        {
            if (record.find(nums[i]) == record.end())
                record.insert({nums[i], {i, 0}});

            auto &cur = record[nums[i]];
            ++cur.second;

            if (cur.second == max_times)
            {
                result = min(result, i - cur.first + 1);
            }
            else if (cur.second > max_times)
            {
                result = i - cur.first + 1;
                max_times = cur.second;
            }
        }
        return result;
    }
};