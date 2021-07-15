/**
 * 剑指 Offer 53 - I. 在排序数组中查找数字 I
 * link：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // int l = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        // int r = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        // return r - l;

        int l = binary_search(nums, target, true);
        int r = binary_search(nums, target, false);
        return r - l + 1;
    }

    int binary_search(vector<int> &nums, int target, bool lower)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            // if (target == nums[mid])
            // {
            //     if (lower)
            //         right = mid - 1;
            //     else
            //         left = mid + 1;
            // }
            // after merging
            if (target < nums[mid] || (lower && target <= nums[mid]))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return lower ? left : right;
    }
};