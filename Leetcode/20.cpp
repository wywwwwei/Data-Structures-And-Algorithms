/**
 * 20. 有效的括号
 * link：https://leetcode-cn.com/problems/valid-parentheses/
 */

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() % 2 != 0)
            return false;

        stack<char> match;
        for (const char &s_char : s)
        {
            if (!match.empty() && match_brace(match.top()) == s_char)
                match.pop();
            else
                match.push(s_char);
        }

        return match.empty();
    }

private:
    char match_brace(const char &c)
    {
        switch (c)
        {
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
        default:
            return 0;
        }
    }
};