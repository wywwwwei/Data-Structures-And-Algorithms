/**
 * 941. 有效的山脉数组
 * link：https://leetcode-cn.com/problems/valid-mountain-array/
 */

class Solution
{
public:
    bool validMountainArray(vector<int> &A)
    {
        int n = A.size();
        if (n < 3)
            return false;

        int left = 0;
        while (left < n - 1 && A[left] < A[left + 1])
            left++;

        if (left >= n - 1 || left == 0 || A[left] == A[left + 1])
            return false;

        while (left < n - 1 && A[left] > A[left + 1])
            left++;
        return left == n - 1;
    }
};