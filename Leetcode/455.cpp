/**
 * 455. 分发饼干
 * link：https://leetcode-cn.com/problems/assign-cookies/
 */

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;

        int n = g.size();
        int m = s.size();
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            while (cur < m && g[i] > s[cur])
                cur++;
            if (cur == m)
                break;
            cur++;
            result++;
        }

        return result;
    }
};