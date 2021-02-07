/**
 * 978. 最长湍流子数组
 * link：https://leetcode-cn.com/problems/longest-turbulent-subarray/
 */

/**
 * dp[i][0] represent the length of a maximum size turbulent subarray ending in i and A[i] < A[i-1]
 * dp[i][1] represent the length of a maximum size turbulent subarray ending in i and A[i] > A[i-1]
 * 
 * 1. A[i] = A[i-1]     ->  dp[i][0] = dp[i][1] = 1
 * 2. A[i] > A[i-1]     ->  dp[i][0] = 1, dp[i][1] = dp[i-1][0] + 1
 * 3. A[i] < A[i-1]     ->  dp[i][0] = dp[i-1][1] + 1, dp[i][1] = 1
 */

class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();

        int greater = 1, less = 1;
        int result = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1])
            {
                greater = 1;
                less = 1;
            }
            else if (arr[i] > arr[i - 1])
            {
                greater = less + 1;
                less = 1;
            }
            else
            {
                less = greater + 1;
                greater = 1;
            }
            result = max(result, max(greater, less));
        }

        return result;
    }
};