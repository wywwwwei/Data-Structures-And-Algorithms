/**
 * 77. 组合 深搜 + 剪枝
 * link：https://leetcode-cn.com/problems/combinations/
 */

class Solution
{
    int numbers;
    int target;
    vector<vector<int>> result;
    vector<int> path;

public:
    vector<vector<int>> combine(int n, int k)
    {
        numbers = n;
        target = k;

        dfs(1);
        return result;
    }

    void dfs(int begin)
    {
        int n = path.size();
        if (n == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = begin; i <= numbers - target + n + 1; i++)
        {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    }
};