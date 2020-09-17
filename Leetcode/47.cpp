/**
 * 47. 全排列 II 回溯
 * link：https://leetcode-cn.com/problems/permutations-ii/
 */

/**
 * To get all possible unique permutations,
 * the key point is that each level of recursion cannot pick duplicate elements.
 * 
 * The general approach is:
 * 1. sort first
 * 2. when searching, judge whether nums[i] and nums[i-1] are equal (duplicate), select it if not, otherwise proceed
 * 3. judge nums[i] and nums[i-1] in the same recursion level, skip if yes, otherwise select it
 */
class Solution
{
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> visited;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        visited.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums);
        return result;
    }

    void dfs(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
                continue;
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums);
            path.pop_back();
            visited[i] = false;
        }
    }
};