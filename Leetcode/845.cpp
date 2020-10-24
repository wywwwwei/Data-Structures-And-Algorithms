/**
 * 845. 数组中的最长山脉
 * link：https://leetcode-cn.com/problems/longest-mountain-in-array/
 */

class Solution
{
public:
    int longestMountain(vector<int> &A)
    {
        int n = A.size();

        int result = 0;
        int left = 0;
        int right = 0;
        while (left + 2 < n)
        {
            right = left + 1;
            if (A[left] < A[left + 1]) // left mountain exists
            {
                while (right + 1 < n && A[right] < A[right + 1]) // left mountain
                    right++;

                if (right < n - 1 && A[right] > A[right + 1]) // right mountain exists
                {
                    while (right < n - 1 && A[right] > A[right + 1]) // right mountain
                        right++;

                    result = max(result, right - left + 1);
                }
                else
                {
                    right++;
                }
            }
            left = right;
        }
        return result;
    }
};