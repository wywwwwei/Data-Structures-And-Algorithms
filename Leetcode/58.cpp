/**
 * 58. 最后一个单词的长度
 * link：https://leetcode-cn.com/problems/length-of-last-word/
 */

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.length() == 0)
            return 0;

        int result = 0;
        int index = 0;
        for (index = s.length() - 1; index >= 0 && s[index] == ' '; index--);
        while (index >= 0 && s[index] != ' ')
        {
            result++;
            index--;
        }
        return result;
    }
};