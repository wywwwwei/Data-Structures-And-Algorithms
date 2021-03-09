/**
 * 224. 基本计算器
 * link：https://leetcode-cn.com/problems/basic-calculator/
 */

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();

        stack<char> sign;
        int result = 0;
        char curSign = 1;

        sign.push(curSign); // the outermost sign is '+'
        for (int i = 0; i < n;)
        {
            switch (s[i])
            {
            case ' ':
                break;
            case '(':
                sign.push(curSign);
                break;
            case ')':
                sign.pop();
                break;
            case '+':
                curSign = sign.top();
                break;
            case '-':
                curSign = -sign.top();
                break;
            default:
                int cur = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9')
                {
                    cur = cur * 10 + (s[i] - '0');
                    i++;
                }

                result += static_cast<int>(curSign) * cur;
                continue;
                break;
            }
            ++i;
        }

        return result;
    }
};