/**
 * 424. 替换后的最长重复字符
 * link：https://leetcode-cn.com/problems/longest-repeating-character-replacement/
 */

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> store(26, 0);

        int left = 0, right = 0;
        int n = s.length();
        int longest;
        while (right < n)
        {
            ++store[s[right] - 'A'];

            // longest = the most times a letter has ever appeared in a window
            // It can only increase because result = right - left = longest(ever-increasing) + k
            longest = max(longest, store[s[right] - 'A']);

            if (right - left + 1 - longest > k) 
            {
                --store[s[left] - 'A'];
                left++;
            }
            right++;
        }

        return right - left;
    }
};