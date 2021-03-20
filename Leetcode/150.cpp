/**
 * 150. 逆波兰表达式求值
 * link：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> stk;

        for (const auto &token : tokens)
        {
            if (isdigit(token.back()))
            {
                stk.push_back(stoi(token));
            }
            else
            {
                int cur = stk.back();
                stk.pop_back();

                switch (token[0])
                {
                case '+':
                    stk.back() += cur;
                    break;
                case '-':
                    stk.back() -= cur;
                    break;
                case '*':
                    stk.back() *= cur;
                    break;
                case '/':
                    stk.back() /= cur;
                    break;
                }
            }
        }

        return stk.back();
    }
};