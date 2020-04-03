/**
 * 42. 接雨水
 * link：https://leetcode-cn.com/problems/trapping-rain-water/
 */

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int index = 0;
        int result = 0;

        while (index < (int)height.size() - 1)
        {
            if (height[index] > 0)
            {
                int j;
                int max_val = INT_MIN;

                //Scan to the right for a position where the value is larger than the current value
                for (j = index + 1; j < height.size() && height[j] < height[index]; j++)
                {
                    max_val = max(height[j], max_val);
                }
                //If found, update max_val because there is no loop for the round
                if (j != height.size())
                {
                    max_val = max(height[j], max_val);
                }

                //The amount of rain received depends on the minimum at both ends
                max_val = min(max_val, height[index]);

                //If the previous scan did not find a larger value, 
                //and j is out of bounds, 
                //we push it back to the position where it is maximum value on the right (less than the current value)
                if (j == height.size())
                {
                    while (height[--j] < max_val);
                }

                for (int i = index + 1; i < j; i++)
                    result += (max_val - height[i]);
                index = j;
            }
            else
            {
                index++;
            }
        }
        return result;
    }
};