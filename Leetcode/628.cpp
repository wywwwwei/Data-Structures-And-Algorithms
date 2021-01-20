/**
 * 628. 三个数的最大乘积
 * link：https://leetcode-cn.com/problems/maximum-product-of-three-numbers/
 */

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int num : nums)
        {
            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }

            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
            {
                max3 = num;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};