/**
 * 7. 整数反转 处理溢出
 * link：https://leetcode-cn.com/problems/reverse-integer/
 */

class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        constexpr int int_min_div = INT_MIN / 10;
        constexpr int int_max_div = INT_MAX / 10;
        constexpr int int_min_remain = INT_MIN % 10;
        constexpr int int_max_remain = INT_MAX % 10;

        while (x != 0)
        {
            int remain = x % 10;
            if (result > int_max_div || (result == int_max_div && remain > int_max_remain))
                return 0;
            if (result < int_min_div || (result == int_min_div && remain < int_min_remain))
                return 0;
            result = result * 10 + remain;
            x = x / 10;
        }
        return result;
    }
};