/**
 * 949. 给定数字能组成的最大时间 枚举
 * link：https://leetcode-cn.com/problems/largest-time-for-given-digits/
 */

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        int result = -1;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == j)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    if (j == k || k == i)
                        continue;

                    int hour = A[i] * 10 + A[j];
                    int min = A[k] * 10 + A[6 - i - j - k];
                    if (hour < 24 && min < 60)
                        result = max(result, hour * 100 + min);
                }
            }
        }
        if (result != -1)
        {
            char str[6];
            sprintf(str, "%2d:%2d", result / 100, result % 100);
            return str;
        }
        return "";
    }
};