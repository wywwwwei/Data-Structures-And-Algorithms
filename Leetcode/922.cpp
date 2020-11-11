/**
 * 922. 按奇偶排序数组 II
 * link：https://leetcode-cn.com/problems/sort-array-by-parity-ii/
 */

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int n = A.size();

        int odd = 1, even = 0;
        while (odd < n)
        {
            if (A[odd] % 2 != 1)
            {
                while (even < n && A[even] % 2 == 0)
                    even += 2;
                swap(A[odd], A[even]);
            }
            odd += 2;
        }

        return A;
    }
};