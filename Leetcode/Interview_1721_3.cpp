/**
 * 面试题 17.21. 直方图的水量 
 * link：https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int result = 0;
        while (left <= right)
        {
            if (leftMax <= rightMax)
            {
                leftMax = max(height[left], leftMax);
                result += leftMax - height[left];
                ++left;
            }
            else
            {
                rightMax = max(height[right], rightMax);
                result += rightMax - height[right];
                --right;
            }
        }

        return result;
    }
};