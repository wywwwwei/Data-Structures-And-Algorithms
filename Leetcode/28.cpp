/**
 * 28. 实现 strStr() KMP
 * link：https://leetcode-cn.com/problems/implement-strstr/
 */

class Solution
{
    void buildLPS(string &needle, int *lps)
    {
        int pos = 0;
        int tablePtr = 1;
        int n = needle.length();

        lps[0] = -1;
        while (tablePtr < n)
        {
            if (needle[pos] == needle[tablePtr])
            {
                lps[tablePtr] = lps[pos];
            }
            else
            {
                lps[tablePtr] = pos;
                pos = lps[pos];
                while (pos >= 0 && needle[pos] != needle[tablePtr])
                    pos = lps[pos];
            }
            pos++;
            tablePtr++;
        }
        lps[n] = pos;
    }

public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.length();
        int n = needle.length();
        if (n > m)
            return -1;
        else if (n == 0)
            return 0;

        int *lps = new int[n + 1];
        buildLPS(needle, lps);

        int i = 0, j = 0;
        while (i < m)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
                if (j == n)
                    return i - n;
            }
            else
            {
                j = lps[j];
                if (j < 0)
                {
                    i++;
                    j++;
                }
            }
        }

        delete[] lps;
        return -1;
    }
};