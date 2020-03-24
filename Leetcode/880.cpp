/**
 * 880. 索引处的解码字符串
 * link：https://leetcode-cn.com/problems/decoded-string-at-index/
 */

/**
 * Because the maximum length of the decoded string is 2 ^ 64,
 * we can't decode directly and we can only get the answer by calculating the index
 * 
 * Because tape is always a string repeated 1 ~ n times (it is 1 when writing alpha), 
 * decode [K] = decode [K % (decode_len / repeat_times)]
 */

class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        unsigned long decode_len = 0;

        for (char &s_char : S)
        {
            if (isdigit(s_char))
                decode_len *= (s_char - '0');
            else
                decode_len++;
        }

        for (int i = S.length() - 1; i >= 0; i--)
        {
            K %= decode_len;

            if(K == 0 && isalpha(S[i]))
                return {S[i]};
            if (isdigit(S[i]))
                decode_len /= (S[i] - '0');
            else
                decode_len--;
        }

        return "";
    }
};