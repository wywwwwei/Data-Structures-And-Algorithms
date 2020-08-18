/**
 * 647. 回文子串
 * link：https://leetcode-cn.com/problems/palindromic-substrings/
 */

/**
 * Solution:
 * 1. Find all substrings and check them.   -> Substring O(N^2) * Check O(N) = O(N^3)
 * 2. Expand Around Center (Find all possible middle of the palindrome) -> Center O(N) * Expand O(N) = O(N^2)
 * 3. Manacher's Algorithm
 */

class Solution
{
public:
    int countSubstrings(string s)
    {
        int result = 0;
        int n = s.length();

        for (int i = 0; i < 2 * n - 1; i++)
        {
            int l = i / 2;
            int r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
                result++;
            }
        }
        return result;
    }
};