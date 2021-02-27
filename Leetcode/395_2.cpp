/**
 * 395. 至少有K个重复字符的最长子串
 * link：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/
 */

/**
 * When there is an interval of length t that satisfies,
 * we can determine that an interval of length t+1 necessarily satisfies or not.
 * It is a property why we use sliding window
 *  
 * When the number of characters contained in the window is determined,
 * the interval regains the above property.
 * 
 * So the main idea is to find all the valid substrings with 
 * a different number of unique characters and track the maximum length.
 */

class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int n = s.length();
        int result = 0;

        for (int i = 1; i <= 26; i++)
        {
            int count[26] = {0};
            int kind = 0;
            int kindNot = 0;

            int l = 0, r = 0;
            while (r < n)
            {
                if (count[s[r] - 'a'] == 0)
                {
                    kind++;
                    kindNot++;
                }
                ++count[s[r] - 'a'];
                if (count[s[r] - 'a'] == k)
                    kindNot--;

                while (kind > i)
                {

                    if (count[s[l] - 'a'] == k)
                        kindNot++;
                    --count[s[l] - 'a'];
                    if (count[s[l] - 'a'] == 0)
                    {
                        kind--;
                        kindNot--;
                    }
                    ++l;
                }

                if (kindNot == 0)
                    result = max(result, r - l + 1);
                ++r;
            }
        }

        return result;
    }
};