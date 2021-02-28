/**
 * 896. 单调数列
 * link：https://leetcode-cn.com/problems/monotonic-array/
 */

class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        int n = A.size();

        bool increase = false;
        bool decrease = false;

        for (int i = 1; i < n; ++i)
        {
            if (A[i] > A[i - 1])
                increase = true;
            else if (A[i] < A[i - 1])
                decrease = true;
        }

        return !(increase && decrease);
    }
};