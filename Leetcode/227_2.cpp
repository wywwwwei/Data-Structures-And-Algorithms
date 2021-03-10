/**
 * 227. 基本计算器 II   stack
 * link：https://leetcode-cn.com/problems/basic-calculator-ii/
 */

class Solution
{
public:
    int calculate(string s)
    {
        int n = s.length();

        vector<int> stk;
        char lastSign = '+';
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i]))
            {
                cur = cur * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)
            {
                switch (lastSign)
                {
                case '+':
                    stk.push_back(cur);
                    break;
                case '-':
                    stk.push_back(-cur);
                    break;
                case '*':
                    stk.back() *= cur;
                    break;
                case '/':
                    stk.back() /= cur;
                default:
                    break;
                }
                lastSign = s[i];
                cur = 0;
            }
        }

        return accumulate(stk.begin(), stk.end(), 0);
    }
};