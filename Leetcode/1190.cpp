/**
 * 1190. 反转每对括号间的子串
 * link：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 */

/**
 * The close parenthesis always matches the nearest open parenthesis, so we store the position of the open parenthesis on the stack
 * ( content )
 * A         A
 * |         |
 * left      right
 * 
 * reverse(left + 1, right) and then remove/erase str[right] first and then str[left].
 * The positions in the stack are not affected because they must precede left.
 */

class Solution
{
public:
    string reverseParentheses(string s)
    {
        int left = 0;
        int right = 0;
        stack<int> parenthese;

        while (right < s.length())
        {
            if (s[right] == ')')
            {
                left = parenthese.top();
                parenthese.pop();
                reverse(s.begin() + left + 1, s.begin() + right);
                s.erase(s.begin() + right);
                s.erase(s.begin() + left);
                right--;
            }
            else if (s[right] == '(')
            {
                parenthese.push(right);
                right++;
            }
            else
            {
                right++;
            }
        }
        return s;
    }
};