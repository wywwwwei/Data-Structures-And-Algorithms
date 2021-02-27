/**
 * 395. 至少有K个重复字符的最长子串 divide and conquer
 * link：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/
 */

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        return dfs(s, 0, s.length() - 1, k);
    }

    int dfs(string &s, int l, int r, int k)
    {
        int count[26] = {0};
        for (int i = l; i <= r; ++i)
            ++count[s[i] - 'a'];

        char split = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (count[i] > 0 && count[i] < k)
            {
                split = 'a' + i;
                break;
            }
        }

        if (split == 0)
            return r - l + 1;

        int right = l;
        int result = 0;
        while (right <= r)
        {
            while (right <= r && s[right] == split)
                ++right;
            if (right > r)
                break;

            int left = right;
            while (right <= r && s[right] != split)
                ++right;
            result = max(result, dfs(s, left, right - 1, k));
        }

        return result;
    }
};