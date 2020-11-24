/**
 * 1370. 上升下降字符串
 * link：https://leetcode-cn.com/problems/increasing-decreasing-string/
 */

class Solution
{
public:
    string sortString(string s)
    {
        int count[26] = {0};
        for (const char &c : s)
            count[c - 'a']++;

        int i = 0;
        int n = s.length();
        string result(n, '0');
        while (i < n)
        {
            for (int j = 0; j < 26; j++)
                if (count[j]-- > 0)
                    result[i++] = j + 'a';

            for (int j = 25; j >= 0; j--)
                if (count[j]-- > 0)
                    result[i++] = j + 'a';
        }

        return result;
    }
};