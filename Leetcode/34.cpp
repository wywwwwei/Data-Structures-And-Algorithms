/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * link：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution
{
    int bSearch(vector<int> &nums, int &target, bool isLeft)
    {
        int left = 0, right = nums.size() - 1;
        int result = nums.size();

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (isLeft && nums[mid] >= target))
            {
                right = mid - 1;
                result = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return result;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = bSearch(nums, target, true);
        int r = bSearch(nums, target, false) - 1;

        if (l <= r && nums[l] == target && nums[r] == target)
            return {l, r};
        return {-1, -1};
    }
};