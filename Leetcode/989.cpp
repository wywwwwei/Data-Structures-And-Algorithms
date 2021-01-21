/**
 * 989. 数组形式的整数加法
 * link：https://leetcode-cn.com/problems/add-to-array-form-of-integer/
 */

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        int carry = K;
        vector<int> B(A);
        int n = A.size();

        for (int i = n - 1; i >= 0; i--)
        {
            carry += B[i];
            B[i] = carry % 10;
            carry /= 10;
        }
        while (carry > 0)
        {
            B.insert(B.begin(), carry % 10);
            carry /= 10;
        }
        return B;
    }
};