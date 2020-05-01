/**
 * 3. 无重复字符的最长子串 Sliding Window
 * link：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int left = 0;
        int right = 0;
        int result = 0;
        bool record[256] = {false};

        while (right < s.length())
        {
            while (right < s.length() && !record[(int)(s[right])])
            {
                record[(int)(s[right++])] = true;
            }
            result = max(result, right - left);
            record[(int)(s[left++])] = false;
        }

        return result;
    }
};