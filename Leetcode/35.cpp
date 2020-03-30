/**
 * 35. 搜索插入位置 二分
 * link：https://leetcode-cn.com/problems/search-insert-position/
 */

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        if (right >= 0 && nums[right] < target)
            return right + 1;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};