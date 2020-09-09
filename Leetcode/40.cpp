/**
 * 40. 组合总和 II 深搜(回溯) + 剪枝
 * link：https://leetcode-cn.com/problems/combination-sum-ii/
 */

/**
 * The problems related to backtracking:
 * 39.combination sum       https://leetcode-cn.com/problems/combination-sum/
 * 40.combination sum ii    https://leetcode-cn.com/problems/combination-sum-ii/
 * 46.permutations          https://leetcode-cn.com/problems/permutations/
 * 47.permutations ii       https://leetcode-cn.com/problems/permutations-ii/
 * 78.subsets               https://leetcode-cn.com/problems/subsets/
 * 90.subsets ii            https://leetcode-cn.com/problems/subsets-ii/
 */

class Solution
{
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return result;
    }

    void dfs(vector<int> &candidates, int begin, int target)
    {
        if (target < 0)
        {
            return;
        }
        else if (target == 0)
        {
            result.push_back(path);
            return;
        }

        for (int i = begin; i < candidates.size(); i++)
        {
            if (i > begin && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            path.pop_back();
        }
    }
};