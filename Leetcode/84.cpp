/**
 * 84. 柱状图中最大的矩形
 * link：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
 */

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // brute force
        // int n = heights.size();
        // int result = 0;
        // for (int left = 0; left < n; ++left)
        // {
        //     int minHeight = INT_MAX;
        //     for (int right = left; right < n; ++right)
        //     {
        //         minHeight = min(minHeight, heights[right]);
        //         result = max(result, (right - left + 1) * minHeight);
        //     }
        // }
        // return result;

        int n = heights.size();
        vector<int> left(n), right(n, n);

        stack<int> minHeight;
        for (int i = 0; i < n; i++)
        {
            while (!minHeight.empty() && heights[minHeight.top()] >= heights[i])
            {
                right[minHeight.top()] = i; // optimization
                minHeight.pop();
            }
            left[i] = (minHeight.empty() ? -1 : minHeight.top());
            minHeight.push(i);
        }

        // for (int i = n; i >= 0; i--)
        // {
        //     while (!minHeight.empty() && heights[minHeight.top()] >= heights[i])
        //         minHeight.pop();
        //     right[i] = (minHeight.empty() ? n : minHeight.top());
        //     minHeight.push(i);
        // }

        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, heights[i] * (right[i] - left[i] - 1));
        return result;
    }
};