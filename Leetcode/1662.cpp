/**
 * 1662. 检查两个字符串数组是否相等
 * link：https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/
 */

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int index1 = 0, index2 = 0;
        int wordIndex1 = 0, wordIndex2 = 0;
        while (index1 < word1.size() && index2 < word2.size())
        {
            if (word1[index1][wordIndex1] != word2[index2][wordIndex2])
            {
                return false;
            }
            wordIndex1++, wordIndex2++;
            if (wordIndex1 >= word1[index1].size())
            {
                index1++;
                wordIndex1 = 0;
            }
            if (wordIndex2 >= word2[index2].size())
            {
                index2++;
                wordIndex2 = 0;
            }
        }
        return index1 == word1.size() && index2 == word2.size();
    }
};