/**
 * 8. 字符串转换整数 (atoi)
 * link：https://leetcode-cn.com/problems/string-to-integer-atoi/ 
 */

class Solution
{
public:
    int myAtoi(string str)
    {
        int res = 0;
        bool negative = false;
        constexpr int int_min_div = INT_MIN / 10;
        constexpr int int_max_div = INT_MAX / 10;
        constexpr int int_min_remain = INT_MIN % 10;
        constexpr int int_max_remain = INT_MAX % 10;

        int index = 0;
        for (index = 0; index < str.length() && str[index] == ' '; index++)
            ;
        if (str[index] == '-')
        {
            negative = true;
            index++;
        }
        else if (str[index] == '+')
            index++;

        for (int i = index; i < str.length(); i++)
        {
            if (str[i] < '0' || str[i] > '9')
                break;
            int remain = str[i] - '0';
            if (negative)
            {
                if (-res < int_min_div || (-res == int_min_div && -remain <= int_min_remain))
                    return INT_MIN;
            }
            else
            {
                if (res > int_max_div || (res == int_max_div && remain >= int_max_remain))
                    return INT_MAX;
            }
            res = res * 10 + remain;
        }
        res = res * (negative ? -1 : 1);
        return res;
    }
};