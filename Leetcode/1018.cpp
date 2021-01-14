/**
 * 1018. 可被 5 整除的二进制前缀
 * link：https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 */

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        int n = A.size();
        vector<bool> result(n, false);

        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = ((cur << 1) + A[i]) % 5;
            result[i] = (cur == 0);
        }
        return result;
    }
};