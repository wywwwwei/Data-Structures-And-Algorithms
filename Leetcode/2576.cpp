/**
 * 2576. 求出最多标记下标 Find the maximum number of marked indices
 * link：https://leetcode.cn/problems/find-the-maximum-number-of-marked-indices/
 */

class Solution
{
public:
    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = n / 2;
        int result = 0;
        for (int i = 0, j = m; i < m && j < n; ++i)
        {
            while (j < n && 2 * nums[i] > nums[j])
            {
                ++j;
            }
            if (j < n)
            {
                result += 2;
                ++j;
            }
        }
        return result;
    }
};