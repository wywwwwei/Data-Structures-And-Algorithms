/**
 * 43. 字符串相乘
 * link：https://leetcode-cn.com/problems/multiply-strings/
 */

/**
 * num1 = a0 * 10^0 + a1 * 10^1 + a2 * 10^2...
 * num2 = b0 * 10^0 + b1 * 10^1 + b2 * 10^2...
 * num1 * num2 = (a0*b0) * 10^0 + (a0*b1 + a1*b0) * 10^1 ...
 */

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.length(), n = num2.length();
        vector<char> a(m, 0);
        vector<char> b(n, 0);
        vector<int> c(m + n, 0);

        for (int i = m - 1, j = 0; i >= 0; i--, j++)
            a[j] = num1[i] - '0';
        for (int i = n - 1, j = 0; i >= 0; i--, j++)
            b[j] = num2[i] - '0';
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                c[i + j] += a[i] * b[j];

        for (int i = 0; i < m + n - 1; i++)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }

        string result;
        int begin = m + n - 1;
        while (begin >= 0 && c[begin] <= 0)
            begin--;
        while (begin >= 0)
            result.push_back(c[begin--] + '0');

        return result;
    }
};