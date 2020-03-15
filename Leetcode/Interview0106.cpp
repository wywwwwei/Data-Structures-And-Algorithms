/**
 * 面试题 01.06. 字符串压缩 模拟
 * link：https://leetcode-cn.com/problems/compress-string-lcci/
 */

class Solution
{
public:
    string compressString(string S)
    {
        if (S.length() == 0)
            return S;
        stringstream result;
        char lastChar = S[0];
        int count = 1;
        for (int i = 1; i < S.length(); i++)
        {
            if (lastChar == S[i])
                count++;
            else
            {
                result << lastChar << count;
                lastChar = S[i];
                count = 1;
            };
        }
        result << lastChar << count;
        return (result.str().length() < S.length() ? result.str() : S);
    }
};