/**
 * 992. K 个不同整数的子数组
 * link：https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
 */

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        int n = A.size();

        vector<int> count1(n + 1, 0), count2(n + 1, 0);
        int left1 = 0, left2 = 0;
        int right = 0;
        int result = 0;
        int cur_count1 = 0, cur_count2 = 0;

        while (right < n)
        {
            if (count1[A[right]] == 0)
                ++cur_count1;
            ++count1[A[right]];
            if (count2[A[right]] == 0)
                ++cur_count2;
            ++count2[A[right]];

            while (cur_count1 > K)
            {
                if (--count1[A[left1]] == 0)
                    --cur_count1;
                ++left1;
            }
            while (cur_count2 > K - 1)
            {
                if (--count2[A[left2]] == 0)
                    --cur_count2;
                ++left2;
            }
            result += left2 - left1;
            ++right;
        }

        return result;
    }
};