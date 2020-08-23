/**
 * 459. 重复的子字符串 枚举
 * link：https://leetcode-cn.com/problems/repeated-substring-pattern/
 */

/**
 * Suppose a string S is constructed with n substrings s
 * S = s + s + s = ns (n >= 2)
 * S + S = 2ns (n >= 2)
 * which means that there must be an S between the beginning of the second s and the end of the penultimate s
 * S[1, n-1] + S[0, n-2] = (The right half of s) + (2n - 2)s + (The left half of s)
 * ∵ n >= 2
 * ∴(2n - 2) >= n
 */

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        return (s + s).find(s, 1) != s.length();
    }
};