/**
 * 945. 使数组唯一的最小增量
 * link：https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
 */

/**
 * 1.Sort and calculate
 *   Time:O(Nlog(N))
 * 2.Calculate while counting (requires array to record)
 *   Time:O(M)  Space:O(M)      M = The maximum value in the input array
 */
class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        if (A.size() <= 0)
            return 0;
        sort(A.begin(), A.end());

        int res = 0;
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i] <= A[i - 1])
            {
                res += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }

        return res;
    }
};