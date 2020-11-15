/**
 * 1021. 删除最外层的括号
 * link：https://leetcode-cn.com/problems/remove-outermost-parentheses/
 */

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string result = "";
        int match = 0;
        for (const char s : S)
        {
            if (s == '(')
            {
                match++;
                if (match == 1)
                    continue;
            }
            else
            {
                match--;
                if (match == 0)
                    continue;
            }
            result += s;
        }
        return result;
    }
};