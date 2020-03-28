/**
 * 820. 单词的压缩编码 逆排序,比较相邻
 * link：https://leetcode-cn.com/problems/short-encoding-of-words/
 */

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        for (auto &word : words)
        {
            reverse(word.begin(), word.end());
        }
        sort(words.begin(), words.end());

        int result = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            int shortLen = words[i].length();
            if (words[i + 1].substr(0, shortLen) != words[i])
            {
                result += shortLen + 1;
            }
        }
        result += words.back().length() + 1;

        return result;
    }
};