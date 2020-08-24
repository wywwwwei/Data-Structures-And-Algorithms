/**
 * 491. 递增子序列 递归枚举
 * link：https://leetcode-cn.com/problems/increasing-subsequences/
 */

/**
 * When enumerating, we will encounter
 * Condition 1: cur < last -> skip to the next
 * Condition 2: cur > last -> select or skip
 * Condition 3: cur == last
 *              3.1 Both selected
 *              3.2 Neither selected
 *              3.3 Only select cur
 *              3.4 Only select last
 * To avoid repetition, we only need to select 3.3 or 3.4
 * 
 * So we need to implement
 * when cur >= last -> select
 * when cur > last -> skip
 */

class Solution
{
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0, INT_MIN);
        return result;
    }

    void dfs(vector<int> &nums, int index, int last)
    {
        if (nums.size() == index)
        {
            if (path.size() >= 2)
                result.push_back(path);
            return;
        }

        if (nums[index] >= last)
        {
            path.push_back(nums[index]);
            dfs(nums, index + 1, nums[index]);
            path.pop_back();
        }

        if (nums[index] != last)
        {
            dfs(nums, index + 1, last);
        }
    }
};