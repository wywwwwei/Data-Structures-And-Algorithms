/**
 * 1004. 最大连续1的个数 III    Sliding window
 * link：https://leetcode-cn.com/problems/max-consecutive-ones-iii/
 */

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int result = INT_MIN;

        for (int left = 0, right = 0; right < A.size(); right++)
        {
            //Comsume
            if (A[right] == 0)
                K--;

            //Recover
            while (K < 0)
            {
                if (A[left++] == 0)
                    K++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};