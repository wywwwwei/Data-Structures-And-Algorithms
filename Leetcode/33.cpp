/**
 * 33. 搜索旋转排序数组 Binary Search
 * link：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int> &nums, int left, int right, int &target)
    {
        if (left == right)
        {
            return nums[left] == target ? left : -1;
        }
        else if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        //Unordered
        if (nums[left] > nums[right])
        {
            //Left ordered
            if (nums[left] <= nums[mid])
            {
                //Target in left
                if (target <= nums[mid] && target >= nums[left])
                    return binarySearch(nums, left, mid, target);
                //Target in right
                else
                    return binarySearch(nums, mid + 1, right, target);
            }
            //Right ordered
            else
            {
                //Target in left
                if (target >= nums[mid] && target <= nums[right])
                    return binarySearch(nums, mid, right, target);
                //Target in right
                else
                    return binarySearch(nums, left, mid - 1, target);
            }
        }
        //Ordered
        else
        {
            if (nums[mid] < target)
                return binarySearch(nums, mid + 1, right, target);
            else
                return binarySearch(nums, left, mid, target);
        }
    }
};