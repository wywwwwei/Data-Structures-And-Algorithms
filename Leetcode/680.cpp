/**
 * 680. 验证回文字符串II 双指针
 * link：https://leetcode-cn.com/problems/valid-palindrome-ii/
 */

/**
 * Consider inequality, because we can delete at most one character, 
 * so there are two options, 
 * 1. delete the character pointed by the previous pointer or   --> index1++
 * 2. delete the character pointed by the following pointer,    --> index2--
 * and judge whether the string between the two pointers is Palindrome
 */
class Solution
{
public:
    bool validPalindrome(string s)
    {
        bool deletion = true;
        int index1 = 0;
        int index2 = s.length() - 1;
        while (index1 < index2)
        {
            if (s[index1] != s[index2])
            {
                return (isPalindrome(s, index1 + 1, index2) || isPalindrome(s, index1, index2 - 1));
            }
            index1++;
            index2--;
        }
        return true;
    }

    bool isPalindrome(string &s, int low, int high)
    {
        for (int i = low, j = high; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};