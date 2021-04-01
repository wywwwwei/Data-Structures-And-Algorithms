/**
 * 面试题 17.21. 直方图的水量 
 * link：https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 */

/**
 * 同 42. 接雨水 https://leetcode-cn.com/problems/trapping-rain-water/
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> leftMax(n);
        int maxVal = height[0];
        for (int i = 0; i < n; ++i)
        {
            maxVal = max(height[i], maxVal);
            leftMax[i] = maxVal;
        }

        vector<int> rightMax(n);
        maxVal = height[n - 1];
        for (int i = n - 1; i >= 0; --i)
        {
            maxVal = max(height[i], maxVal);
            rightMax[i] = maxVal;
        }

        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            int h = min(leftMax[i], rightMax[i]);
            if (h > height[i])
                result += h - height[i];
        }

        return result;
    }
};