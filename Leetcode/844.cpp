/**
 * 844. 比较含退格的字符串
 * link：https://leetcode-cn.com/problems/backspace-string-compare/
 */

class Solution
{
    void moveToNext(string &S, int &ptr, int &backspace)
    {
        while (ptr >= 0)
        {
            if (S[ptr] == '#')
                backspace++;
            else if (backspace > 0)
                backspace--;
            else
                break;
            ptr--;
        }
    }

public:
    bool backspaceCompare(string S, string T)
    {
        int s_ptr = S.length() - 1;
        int t_ptr = T.length() - 1;

        int s_backspace = 0;
        int t_backspace = 0;
        while (s_ptr >= 0 && t_ptr >= 0)
        {
            moveToNext(S, s_ptr, s_backspace);
            moveToNext(T, t_ptr, t_backspace);
            if (s_ptr >= 0 && t_ptr >= 0)
            {
                if (S[s_ptr--] != T[t_ptr--])
                    return false;
            }
        }
        moveToNext(S, s_ptr, s_backspace);
        moveToNext(T, t_ptr, t_backspace);
        return (s_ptr < 0 && t_ptr < 0);
    }
};