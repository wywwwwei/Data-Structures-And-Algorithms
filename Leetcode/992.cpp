/**
 * 992. K 个不同整数的子数组
 * link：https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
 */

/**
 * Solution 1: subarrays with k different integers 
 *             = subarrays with at most k different integers - subarrays with at most k-1 different integers
 * can be solved by sliding windows easily
 * 
 * Solution 2: subarrays with k different integers
 *             ->   brute force  -> for each r, check if arr[l,r] (0 <= l < r) contains k different integers
 *             -> if r increases, l must stays or increases    ->   there may be more than one l
 *             -> for each l, arr[l,r] increases result by 1   ->   record left l and right l   -> result += right l - left l
 */
class Solution
{
    int subarraysMostKDistinct(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> count(n + 1, 0);

        int left = 0, right = 0;
        int cur_count = 0;
        int result = 0;

        while (right < n)
        {
            if (count[A[right]] == 0)
                ++cur_count;
            ++count[A[right]];
            ++right;

            while (cur_count > K)
            {
                if (--count[A[left]] == 0)
                    --cur_count;
                left++;
            }

            result += right - left;
        }

        return result;
    }

public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return subarraysMostKDistinct(A, K) - subarraysMostKDistinct(A, K - 1);
    }
};