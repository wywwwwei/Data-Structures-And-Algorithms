/**
 * 22. 括号生成 dfs+剪枝
 * link：https://leetcode-cn.com/problems/generate-parentheses/
 */

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {""};
        vector<string> result;
        string cur_result(n * 2, '(');
        dfs(result, cur_result, n - 1, n, n);
        return result;
    }

    void dfs(vector<string> &result, string &cur_result, int left, int right, int n)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(cur_result);
            return;
        }
        if (left >= right)
        {
            cur_result[n - left + n - right] = '(';
            dfs(result, cur_result, left - 1, right, n);
        }
        else
        {
            if (right > 0)
            {
                cur_result[n - left + n - right] = ')';
                dfs(result, cur_result, left, right - 1, n);
            }
            if (left > 0)
            {
                cur_result[n - left + n - right] = '(';
                dfs(result, cur_result, left - 1, right, n);
            }
        }
    }
};