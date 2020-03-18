/**
 * 409. 最长回文串
 * link：https://leetcode-cn.com/problems/longest-palindrome/
 */

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> statistics;

        for (char &i : s)
        {
            statistics[i]++;
        }

        int odd_num = 0;
        for (auto &i : statistics)
        {
            if (i.second % 2 == 1)
                odd_num++;
        }

        return odd_num > 0 ? s.length() - odd_num + 1 : s.length();
    }
};