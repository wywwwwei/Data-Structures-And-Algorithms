/**
 * 152. 乘积最大子数组 dp
 * link：https://leetcode-cn.com/problems/maximum-product-subarray/
 */

/**
 * To find max product
 * if nums[i] < 0, we hope the product[i - 1] as small as possible
 * if nums[i] > 0, we hope the product[i - 1] as large as possible
 * if nums[i] == 0, we need to recalculate, or not product will always be 0
 * -> max_product[i] = max(nums[i], max_product[i - 1] * nums[i])
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int cur_max = 1;
        int cur_min = 1;
        int last_max;
        int result = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            last_max = cur_max;
            cur_max = max(nums[i], max(cur_max * nums[i], cur_min * nums[i]));
            cur_min = min(nums[i], min(last_max * nums[i], cur_min * nums[i]));
            result = max(result, cur_max);
        }

        return result;
    }
};