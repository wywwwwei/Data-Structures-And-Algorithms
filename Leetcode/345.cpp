/**
 * 345. 反转字符串中的元音字母 双指针
 * link：https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
 */

class Solution
{
public:
    string reverseVowels(string s)
    {
        if (s.empty())
        {
            return s;
        }
        int index1 = 0;
        int index2 = s.length() - 1;
        while (index1 < index2)
        {
            while (index1 < index2 && !isVowel(s[index1]))
                index1++;
            while (index1 < index2 && !isVowel(s[index2]))
                index2--;
            if (index1 != index2)
            {
                swap(s[index1], s[index2]);
                index1++;
                index2--;
            }
        }
        return s;
    }

    bool isVowel(char temp)
    {
        return (temp == 'a' || temp == 'A' || temp == 'o' || temp == 'O' || temp == 'e' || temp == 'E' || temp == 'i' || temp == 'I' || temp == 'u' || temp == 'U');
    }
};