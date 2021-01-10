/**
 * 228. 汇总区间
 * link：https://leetcode-cn.com/problems/summary-ranges/
 */

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {

        int n = nums.size();
        if (n <= 0)
            return {};

        int begin = 0;
        int end = 1;
        vector<string> result;
        while (end < n)
        {
            if (nums[end] - 1 != nums[end - 1])
            {
                if (end - begin > 1)
                    result.push_back(to_string(nums[begin]) + "->" + to_string(nums[end - 1]));
                else
                    result.push_back(to_string(nums[begin]));
                begin = end;
            }
            end++;
        }
        if (end - begin > 1)
            result.push_back(to_string(nums[begin]) + "->" + to_string(nums[end - 1]));
        else
            result.push_back(to_string(nums[begin]));
        return result;
    }
};