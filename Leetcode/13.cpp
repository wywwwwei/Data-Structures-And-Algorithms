/**
 * 13. 罗马数字转整数
 * link：https://leetcode-cn.com/problems/roman-to-integer/
 */

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;

        for (int i = 0; i < s.length(); i++)
        {
            int cur = roman2int(s[i]);
            int prev = i > 0 ? roman2int(s[i - 1]) : 1000;
            if (cur > prev)
                result -= prev * 2;
            result += cur;
        }

        return result;
    }

private:
    int roman2int(char &s) const
    {
        switch (s)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
};