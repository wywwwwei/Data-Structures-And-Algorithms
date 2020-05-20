/**
 * 1371. 每个元音包含偶数次的最长子字符串
 * link：https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
 */

/**
 * Start by brute force: record the status of each substring. -> O(n^2)
 * 
 * Thinking of 560.Subarray Sum Equals K, we can use prefix sum to avoid enumerating all substrings -> O(n)
 * 
 * Represent a state: Starting with parity, 0 means even, 1 means odd, and each bit represents a vowel. -> 1 << 5 states
 * We want to get the state that all vowels are even, that is, 00000, 
 * appears only when two prefix sums equal.
 * 
 * Longest -> The position where the current state appears for the first time + 1 ~ current position
 */
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        vector<int> record(1 << 5, -1);
        int cur_status = 0;
        int result = 0;

        record[cur_status] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
                cur_status ^= 1;
            else if (s[i] == 'e')
                cur_status ^= (1 << 1);
            else if (s[i] == 'i')
                cur_status ^= (1 << 2);
            else if (s[i] == 'o')
                cur_status ^= (1 << 3);
            else if (s[i] == 'u')
                cur_status ^= (1 << 4);

            if (~record[cur_status])
                result = max(result, i + 1 - record[cur_status]);
            else
                record[cur_status] = i + 1;
        }

        return result;
    }
};