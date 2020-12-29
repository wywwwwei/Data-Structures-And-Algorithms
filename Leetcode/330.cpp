/**
 * 330. 按要求补齐数组
 * link：https://leetcode-cn.com/problems/patching-array/
 */

/**
 * When [1,x-1] is covered, adding x is the best way to expand coverage. Because
 * 1. add a < x, then [1,<2x-1] is worse than [1,2x-1]
 * 2. add a > x, then [1,x-1] and [a,x+a-1] are covered but we need to fill [x,a-1]
 */
class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int result = 0;
        long cover = 1;
        int m = nums.size();
        int i = 0;

        while (cover <= n)
        {
            if (i < m && cover >= nums[i])
            {
                cover += nums[i++];
            }
            else
            {
                cover += cover;
                result++;
            }
        }
        return result;
    }
};