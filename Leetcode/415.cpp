/**
 * 415. 字符串相加  Elementary Math
 * link：https://leetcode-cn.com/problems/add-strings/
 */

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        char carry = 0;
        int m = num1.length(), n = num2.length();

        int i, j;
        string result;
        for (i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
        {
            char sum = (i >= 0 ? (num1[i] - '0') : 0) + (j >= 0 ? (num2[j] - '0') : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            result.push_back('0' + sum);
        }
        if (carry)
            result.push_back('0' + carry);

        reverse(result.begin(), result.end());
        return result;
    }
};