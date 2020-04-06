/**
 * 5. 最长回文子串 Manacher's Algorithm
 * link：https://leetcode-cn.com/problems/longest-palindromic-substring/
 */

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string temp = fillString(s);
        vector<int> p(temp.length(), 0);

        int c = 0;
        int r = 0;
        int index = 0;
        int max_len = 0;
        for (int i = 0; i < temp.length(); i++)
        {
            int mirror = 2 * c - i;

            if (i < r)
            {
                p[i] = min(r - i, p[mirror]);
            }

            int l_tmp = i - p[i] - 1;
            int r_tmp = i + p[i] + 1;
            while (l_tmp >= 0 && r_tmp < temp.length() && temp[l_tmp] == temp[r_tmp])
            {
                p[i]++;
                l_tmp--;
                r_tmp++;
            }

            if (i + p[i] > r)
            {
                c = i;
                r = i + p[i];
                if (p[i] > max_len)
                {
                    index = i;
                    max_len = p[i];
                }
            }
        }

        return s.substr((index - max_len) / 2, max_len);
    }

    string fillString(string &s)
    {
        int fill_len = 2 * s.length() + 1;
        string result(fill_len, '#');

        for (int i = 1, j = 0; i < fill_len && j < s.length(); i += 2, j++)
        {
            result[i] = s[j];
        }

        return result;
    }
};