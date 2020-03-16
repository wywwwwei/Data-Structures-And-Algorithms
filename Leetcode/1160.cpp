/**
 * 1160. 拼写单词 计数
 * link：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
 */

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int res_sum = 0;
        vector<int> char_set(26, 0);
        vector<int> char_need(26, 0);

        for (char char_byte : chars)
            char_set[char_byte - 'a']++;

        for (string &word : words)
        {
            char_need.assign(char_set.begin(), char_set.end());

            bool learn = true;
            for (char char_byte : word)
            {
                if (--char_need[char_byte - 'a'] < 0)
                {
                    learn = false;
                    break;
                }
            }
            if (learn)
                res_sum += word.length();
        }

        return res_sum;
    }
};