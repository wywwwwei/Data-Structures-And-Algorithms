/**
 * 242. 有效的字母异位词
 * link：https://leetcode-cn.com/problems/valid-anagram/
 */

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int count[26] = {0};
        for (const char &c : s)
            count[c - 'a']++;
        for (const char &c : t)
            count[c - 'a']--;
        return all_of(count, count + 26, [](const int &a) -> bool {
            return a == 0;
        });
    }
};