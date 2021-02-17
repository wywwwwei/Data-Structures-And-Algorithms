/**
 * 995. K 连续位的最小翻转次数
 * link：https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/
 */

/**
 * For several K-bit flipping operations, changing the sequence does not affect the final flipping result
 * Minimum number of flips -> from left to right flip each k-consecutive-bit starts with 0
 * brute force  ->  record flip range
 */

class Solution
{
public:
    int minKBitFlips(vector<int> &A, int K)
    {
        int n = A.size();

        int reverse = 0;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i >= K && A[i - K] > 1)
            {
                reverse ^= 1;
                A[i - K] -= 2;
            }
            if (A[i] == reverse)
            {
                if (i + K > n)
                    return -1;
                ++result;
                reverse ^= 1;
                A[i] += 2;
            }
        }
        return result;
    }
};