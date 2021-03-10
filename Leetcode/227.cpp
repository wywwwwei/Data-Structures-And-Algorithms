/**
 * 227. 基本计算器 II
 * link：https://leetcode-cn.com/problems/basic-calculator-ii/
 */

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();

        char sign = '+';
        int result = 0;
        int cur = 0;
        int last = 0;

        for (int i = 0; i < n; ++i)
        {
            char curChar = s[i];
            if (isdigit(curChar))
            {
                cur = (cur * 10) + (curChar - '0');
            }
            if (!isdigit(curChar) && !iswspace(curChar) || i == n - 1)
            {
                if (sign == '+' || sign == '-')
                {
                    result += last;
                    last = (sign == '+' ? cur : -cur);
                }
                else if (sign == '*')
                {
                    last *= cur;
                }
                else if (sign == '/')
                {
                    last /= cur;
                }
                sign = curChar;
                cur = 0;
            }
        }
        result += last;

        return result;
    }
};