/**
 * 387. 字符串中的第一个唯一字符
 * link：https://leetcode-cn.com/problems/first-unique-character-in-a-string/
 */

class Solution
{
    enum
    {
        kInit = -1,
        kRepeat = -2
    };

public:
    int firstUniqChar(string s)
    {
        int idx[26];

        fill(idx, idx + 26, kInit);

        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (idx[c] != kInit)
                idx[c] = kRepeat;
            else
                idx[c] = i;
        }

        int result = INT_MAX;
        bool exist = false;
        for (int i = 0; i < 26; i++)
            if (idx[i] != kInit && idx[i] != kRepeat)
            {
                exist = true;
                result = min(result, idx[i]);
            }

        return exist ? result : -1;
    }
};