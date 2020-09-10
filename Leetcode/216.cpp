/**
 * 216. 组合总和 III 深搜(回溯) + 剪枝
 * link：https://leetcode-cn.com/problems/combination-sum-iii/
 */

class Solution
{
    vector<vector<int>> result;
    vector<int> path;
    int len_;

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        len_ = k;
        dfs(1, n);
        return result;
    }

    void dfs(int begin, int target)
    {
        if (path.size() == len_)
        {
            if (target == 0)
            {
                result.push_back(path);
            }
            return;
        }
        if (target <= 0)
            return;

        for (int i = begin; i <= 9; i++)
        {
            path.push_back(i);
            dfs(i + 1, target - i);
            path.pop_back();
        }
    }
};