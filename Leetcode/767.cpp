/**
 * 767. 重构字符串
 * link：https://leetcode-cn.com/problems/reorganize-string/
 */

class Solution
{
public:
    string reorganizeString(string S)
    {
        int n = S.length();
        if (n < 2)
            return S;

        int count[26] = {0};
        int pos = 0;
        for (const char &c : S)
        {
            count[c - 'a']++;
            if (count[c - 'a'] > (n + 1) / 2)
                return "";
            else if (count[c - 'a'] == (n + 1) / 2)
                pos = c - 'a';
        }

        string result(n, 0);
        for (int i = 0; i < n; i += 2)
        {
            while (count[pos] <= 0)
                pos = (pos + 1) % 26;
            result[i] = pos + 'a';
            count[pos]--;
        }
        for (int i = 1; i < n; i += 2)
        {
            while (count[pos] <= 0)
                pos = (pos + 1) % 26;
            result[i] = pos + 'a';
            count[pos]--;
        }
        return result;
    }
};