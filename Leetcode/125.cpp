/**
 * 125. 验证回文串
 * link：https://leetcode-cn.com/problems/valid-palindrome/
 */

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.size() <= 0)
            return true;
        int i = 0;
        int j = s.length() - 1;
        while (i < j)
        {
            while (i < j && !isdigit(s[i]) && !isalpha(s[i]))
                i++;
            while (i < j && !isdigit(s[j]) && !isalpha(s[j]))
                j--;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }
        return true;
    }
};