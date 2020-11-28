/**
 * 976. 三角形的最大周长
 * link：https://leetcode-cn.com/problems/largest-perimeter-triangle/
 */

class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        int n = A.size();
        sort(A.begin(), A.end(), greater<int>());

        for (int i = 0; i < n - 2; i++)
        {
            if (A[i + 1] + A[i + 2] > A[i])
                return A[i] + A[i + 1] + A[i + 2];
        }
        return 0;
    }
};