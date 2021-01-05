/**
 * 830. 较大分组的位置
 * link：https://leetcode-cn.com/problems/positions-of-large-groups/
 */

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        vector<vector<int>> result;

        int n = s.length();
        int begin = 0, end = 1;

        while (end < n)
        {
            if (s[end] != s[end - 1])
            {
                if (end - begin >= 3)
                    result.push_back({begin, end - 1});
                begin = end;
            }
            end++;
        }
        if (end - begin >= 3)
            result.push_back({begin, end - 1});
        return result;
    }
};