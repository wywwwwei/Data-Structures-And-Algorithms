/**
 * 135. 分发糖果
 * link：https://leetcode-cn.com/problems/candy/
 */

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int result = 1;

        int dec_len = 0;
        int inc_len = 0;
        int prev = 1;

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] < ratings[i - 1])
            {
                prev = 1;
                ++dec_len;
                if (dec_len > inc_len) // Decreasing sequences are longer than increasing sequences
                    ++result;          // Give one more candy to the child at the top of the mountain
                result += dec_len;
            }
            else if (ratings[i] == ratings[i - 1])
            {
                dec_len = inc_len = 0;
                prev = 1;
                ++result;
            }
            else
            {
                dec_len = 0;
                inc_len = prev;
                ++prev;
                result += prev;
            }
        }
        return result;
    }
};