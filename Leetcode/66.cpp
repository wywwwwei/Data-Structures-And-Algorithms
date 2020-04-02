/**
 * 66. 加一
 * link：https://leetcode-cn.com/problems/plus-one/
 */

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool carry = false;
        digits[digits.size() - 1] += 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += (carry ? 1 : 0);
            carry = (digits[i] >= 10 ? true : false);
            digits[i] %= 10;
            if (!carry)
                return digits;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};