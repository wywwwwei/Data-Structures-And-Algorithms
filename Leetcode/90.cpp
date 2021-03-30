/**
 * 90. 子集 II
 * link：https://leetcode-cn.com/problems/subsets-ii/
 */

class Solution
{
    vector<vector<int>> result;
    vector<int> curPath;

    void dfs(vector<int> &nums, int idx, bool prev)
    {
        if (idx == nums.size())
        {
            result.push_back(curPath);
            return;
        }

        dfs(nums, idx + 1, false);

        // avoid repeat
        // 1. if this one is added, then all the same value behind it are added
        // 2. if this one is not added, then all the same value behind it can not be added
        // here is the second choice
        if (!prev && idx > 0 && nums[idx] == nums[idx - 1])
            return;

        curPath.push_back(nums[idx]);
        dfs(nums, idx + 1, true);
        curPath.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, false);
        return result;
    }
};