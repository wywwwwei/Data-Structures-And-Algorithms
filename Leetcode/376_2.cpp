/**
 * 376. 摆动序列    dp
 * link：https://leetcode-cn.com/problems/wiggle-subsequence/
 */

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = unique(nums.begin(), nums.end()) - nums.begin();
        if (n <= 2)
            return n;

        int up = 1, down = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
                up = max(down + 1, up);
            else
                down = max(up + 1, down);
        }
        return max(up, down);
    }
};