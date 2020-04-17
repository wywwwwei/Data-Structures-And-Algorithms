/**
 * 11. 盛最多水的容器 双指针
 * link：https://leetcode-cn.com/problems/container-with-most-water/
 */

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right)
        {
            if (height[left] >= height[right])
            {
                result = max(result, height[right] * (right - left));
                right--;
            }
            else
            {
                result = max(result, height[left] * (right - left));
                left++;
            }
        }
        return result;
    }
};