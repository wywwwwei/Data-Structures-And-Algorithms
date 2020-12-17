/**
 * 389. 找不同
 * link：https://leetcode-cn.com/problems/find-the-difference/
 */

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int count[26] = {0};
        for (const char c : s)
            count[c - 'a']++;
        for (const char c : t)
            if (count[c - 'a']-- <= 0)
                return c;
        return ' ';
    }
};