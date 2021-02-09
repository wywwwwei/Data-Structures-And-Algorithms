/**
 * 567. 字符串的排列
 * link：https://leetcode-cn.com/problems/permutation-in-string/
 */

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        if (m > n)
            return false;

        int count[26] = {0};
        for (int i = 0; i < m; ++i)
        {
            --count[s1[i] - 'a'];
            ++count[s2[i] - 'a'];
        }

        int diff = 0;
        for (int c : count)
            if (c != 0)
                ++diff;
        if (diff == 0)
            return true;

        for (int i = m; i < n; i++)
        {
            int idx_r = s2[i] - 'a', idx_l = s2[i - m] - 'a';
            if (idx_l == idx_r)
                continue;

            // 1 -> 0  or 0 -> -1
            if (count[idx_l] == 0)
                ++diff;
            --count[idx_l];
            if (count[idx_l] == 0)
                --diff;

            // 0 -> 1 or -1 -> 0
            if (count[idx_r] == 0)
                ++diff;
            ++count[idx_r];
            if (count[idx_r] == 0)
                --diff;

            if (diff == 0)
                return true;
        }
        return false;
    }
};