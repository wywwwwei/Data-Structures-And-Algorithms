/**
 * 283. 移动零
 * link：https://leetcode-cn.com/problems/move-zeroes/
 */

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int scan = 0;
        int nonzero = 0;

        while (scan < n)
        {
            if (nums[scan])
            {
                swap(nums[scan], nums[nonzero]);
                nonzero++;
            }
            scan++;
        }
    }
};