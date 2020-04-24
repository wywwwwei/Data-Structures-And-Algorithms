/**
 * 46. 全排列 dfs
 * link：https://leetcode-cn.com/problems/permutations/
 */

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        dfs(result, nums, 0);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &nums, int step)
    {
        if (step == nums.size())
        {
            result.emplace_back(nums);
            return;
        }

        for (int i = step; i < nums.size(); i++)
        {
            swap(nums[i], nums[step]);
            dfs(result, nums, step + 1);
            swap(nums[i], nums[step]);
        }
    }
};