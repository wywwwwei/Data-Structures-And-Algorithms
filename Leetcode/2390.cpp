/**
 * 2390. 从字符串中移除星号 Removing stars from a string
 * link：https://leetcode.cn/problems/removing-stars-from-a-string
 */

class Solution
{
public:
    string removeStars(string s)
    {
        string result;
        for (const char &c : s)
        {
            if (c == '*')
            {
                result.pop_back();
            }
            else
            {
                result.push_back(c);
            }
        }
        return result;
    }
};