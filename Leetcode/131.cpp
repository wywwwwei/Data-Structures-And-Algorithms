/**
 * 131. 分割回文串
 * link：https://leetcode-cn.com/problems/palindrome-partitioning/
 */

class Solution
{
    vector<vector<string>> result;
    vector<vector<bool>> ifPalindrome;

    vector<string> curPath;
    int n;

    void dfs(string &s, int idx)
    {
        if (idx == n)
        {
            result.push_back(curPath);
            return;
        }

        for (int i = idx; i < n; ++i)
        {
            if (ifPalindrome[idx][i])
            {
                curPath.emplace_back(s.substr(idx, i - idx + 1));
                dfs(s, i + 1);
                curPath.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        n = s.length();
        
        // ifPalindrome.assign(n, vector<bool>(n, false));
        // for (int i = 0; i < 2 * n; i++)
        // {
        //     int left = i / 2;
        //     int right = (i + 1) / 2;
        //     while (left >= 0 && right < n && s[left] == s[right])
        //     {
        //         ifPalindrome[left][right] = true;
        //         --left;
        //         ++right;
        //     }
        // }

        ifPalindrome.assign(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 1; j < n; ++j)
                ifPalindrome[i][j] = s[i] == s[j] && ifPalindrome[i + 1][j - 1];

        dfs(s, 0);

        return result;
    }
};