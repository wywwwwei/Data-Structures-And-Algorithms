/**
 * 459. 重复的子字符串 枚举
 * link：https://leetcode-cn.com/problems/repeated-substring-pattern/
 */

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int i = 1; i * 2 <= n; i++)
        {
            if (n % i == 0)
            {
                bool match = true;
                for (int j = i; j < n; j++)
                {
                    if (s[j - i] != s[j])
                    {
                        match = false;
                        break;
                    }
                }
                if (match)
                    return true;
            }
        }

        return false;
    }
};