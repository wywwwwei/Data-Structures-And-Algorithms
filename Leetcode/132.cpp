/**
 * 132. 分割回文串 II
 * link：https://leetcode-cn.com/problems/palindrome-partitioning-ii/
 */

class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();

        vector<vector<bool>> ifPalindrome(n, vector<bool>(n, false));
        for (int i = 0; i < 2 * n; i++)
        {
            int left = i / 2;
            int right = (i + 1) / 2;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                ifPalindrome[left][right] = true;
                --left;
                ++right;
            }
        }

        // vector<vector<bool>> ifPalindrome(n, vector<bool>(n, true));
        // for (int i = n - 1; i >= 0; --i)
        //     for (int j = i + 1; j < n; ++j)
        //         ifPalindrome[i][j] = s[i] == s[j] && ifPalindrome[i + 1][j - 1];

        // dp[i] represents the min # of partition
        // dp[i] = min(dp[j-1] + 1)  for j in [0,i] and [j,i] is palindrome
        vector<int> dp(n + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j > 0; --j)
                if (ifPalindrome[j - 1][i - 1])
                    dp[i] = min(dp[i], dp[j - 1] + 1);

        // slice = partition - 1
        return dp[n] - 1;
    }
};