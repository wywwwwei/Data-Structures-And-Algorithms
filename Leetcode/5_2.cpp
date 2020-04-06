/**
 * 5. 最长回文子串 Expand Around Center
 * link：https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 0)
            return "";

        int index = 0;
        int res_len = 1;
        for (int i = 0; i < s.length(); i++)
        {
            int len = max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i + 1));
            if (len > res_len)
            {
                index = i - ((len - 1) / 2);
                res_len = len;
            }
        }

        return s.substr(index, res_len);
    }

    int expandAroundCenter(string &s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};