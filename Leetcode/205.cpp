/**
 * 205. 同构字符串
 * link：https://leetcode-cn.com/problems/isomorphic-strings/
 */

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        if (n != m)
            return false;

        int s_count[128] = {0};
        int t_count[128] = {0};
        char s_match[128] = {0};
        char t_match[128] = {0};
        for (int i = 0; i < n; i++)
        {
            char cur_s = s[i];
            char cur_t = t[i];
            if (!(s_match[cur_s] == 0 && s_match[cur_s] == t_match[cur_t]) && (s_match[cur_s] != t[i] || t_match[cur_t] != s[i]))
                return false;
            if (s_count[cur_s] != t_count[cur_t])
                return false;
            s_match[cur_s] = t[i];
            t_match[cur_t] = s[i];
            ++s_count[cur_s];
            ++t_count[cur_t];
        }

        return true;
    }
};