/**
 * 面试题 17.21. 直方图的水量 
 * link：https://leetcode-cn.com/problems/volume-of-histogram-lcci/
 */

/**
 * Implementing merging-like operations through a monotone stack
 * e.g.     Here we'll only talk about the height, because the width is easy to calculate as long as we save the index
 * 
 * [0,1,0,2,1,0,1,3,2,1,2,1] - 0 -> [1,0,2,1,0,1,3,2,1,2,1] - 1 * 1 -> [2,1,0,1,3,2,1,2,1]  - 1 * 1 -> [2,1,3,2,1,2,1]
 * - 1 * 3 -> [3,2,1,2,1] - 1 * 1 -> [3,2,1]
 * 
 * It's like merging the valley
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> stk;
        int result = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!stk.empty() && height[stk.back()] < height[i])
            {
                int bound = stk.back();
                stk.pop_back();
                if (stk.empty())
                    break;
                result += (i - stk.back() - 1) * (min(height[i], height[stk.back()]) - height[bound]);
            }
            stk.emplace_back(i);
        }

        return result;
    }
};