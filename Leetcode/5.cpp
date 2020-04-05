/**
 * 5. 最长回文子串 dp
 * link：https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int index1 = 0;
        int res_len = 1;
        int s_len = s.length();
        if (s_len == 0)
            return "";

        vector<bool> dp(s_len, false);
        for (int i = s_len - 1; i >= 0; i--)
        {
            for (int j = s_len - 1; j >= i; j--)
            {
                dp[j] = (j - i <= 2 || dp[j - 1]) && (s[i] == s[j]);
                if (dp[j])
                {
                    int len = j - i + 1;
                    if (res_len < len)
                    {
                        index1 = i;
                        res_len = len;
                    }
                }
            }
        }
        // Optimize space complexity
        // vector<vector<bool>> dp(s_len, vector<bool>(s_len, false));
        // for (int i = 0; i < s_len; i++)
        //     dp[i][i] = true;
        // for (int i = 0; i < s_len - 1; i++)
        // {
        //     if (s[i] == s[i + 1])
        //     {
        //         dp[i][i + 1] = true;
        //         index1 = i;
        //         res_len = 2;
        //     }
        // }

        // for (int len = 2; len < s_len; len++)
        // {
        //     for (int i = 0; i < s_len - len; i++)
        //     {
        //         if (dp[i + 1][i + len - 1] && s[i] == s[i + len])
        //         {
        //             dp[i][i + len] = true;
        //             index1 = i;
        //             res_len = 1 + len;
        //         }
        //     }
        // }

        return s.substr(index1, res_len);
    }
};