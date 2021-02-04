/**
 * 1208. 尽可能使字符串相等
 * link：https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
 */

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int cur = 0;

        int left = 0, right = 0;
        int result = 0;
        while (right < n)
        {
            cur += abs(s[right] - t[right]);
            while (cur > maxCost)
            {
                cur -= abs(s[left] - t[left]);
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};