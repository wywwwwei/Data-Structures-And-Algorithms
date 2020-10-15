/**
 * 977. 有序数组的平方
 * link：https://leetcode-cn.com/problems/squares-of-a-sorted-array/
 */

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int n = A.size();
        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int count = n - 1;
        while (count >= 0)
        {
            if (A[left] * A[left] > A[right] * A[right])
                result[count--] = A[left] * A[left++];
            else
                result[count--] = A[right] * A[right--];
        }

        return result;
    }
};