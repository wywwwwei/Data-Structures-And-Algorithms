/**
 * 224. 基本计算器
 * link：https://leetcode-cn.com/problems/basic-calculator/
 */

/**
 * (1+(4+5+2)-3)+(6+8) = + 1 + 4 + 5 + 2 - 3 + 6 + 8
 * (1-(4+5+2)-3)+(6+8) = + 1 - 4 - 5 - 2 - 3 + 6 + 8
 * 
 * Each time we walk through a number, the operator for that number is known,
 * so we only need a stack to keep track of the sign of each pair of parentheses
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