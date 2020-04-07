/**
 * 392. 判断子序列 双指针
 * link：https://leetcode-cn.com/problems/is-subsequence/
 */

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.length() <= 0)
            return true;
        if (s.length() > t.length())
            return false;

        int index = 0;
        for (const char &c : t)
        {
            if (c == s[index])
                index++;
            if (index == s.length())
                return true;
        }
        
        return false;
    }
};