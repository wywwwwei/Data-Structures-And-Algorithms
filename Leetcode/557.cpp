/**
 * 557. 反转字符串中的单词 III
 * link：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = 0;
        int right = 0;

        while (left < s.length())
        {
            while (right < s.length() && s[right] != ' ')
                right++;
            for (int i = left, j = right - 1; i < j; i++, j--)
                swap(s[i], s[j]);
            left = ++right;
        }

        return s;
    }
};