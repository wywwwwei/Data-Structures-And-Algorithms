/**
 * 152. 乘积最大子数组
 * link：https://leetcode-cn.com/problems/maximum-product-subarray/
 */

/**
 * Consider no 0 in nums
 * if there are an even number of negative numbers, then max product = nums[0] * nums[1] ... nums[nums.size() - 1]
 * if there are an odd number of negative numbers, the max product = 
 * max(nums[0] * nums[1] ... nums before the last negative number, nums after the first negative number * ... * nums[nums.size() - 1 ])
 * 
 * Consider 0 in nums
 * 0 divides the array into multiple subarrays that do not contain 0
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int cur_product = 1;
        int result = INT_MIN;

        for (auto &num : nums)
        {
            cur_product = cur_product * num;
            if (cur_product > result)
                result = cur_product;
            if (cur_product == 0)
                cur_product = 1;
        }

        cur_product = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            cur_product = cur_product * nums[i];
            if (cur_product > result)
                result = cur_product;
            if (cur_product == 0)
                cur_product = 1;
        }

        return result;
    }
};