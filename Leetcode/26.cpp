/**
 * 26. 删除排序数组中的重复项
 * link：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

/**
 * It doesn't matter what you leave beyond the returned length!!!
 * So we just need to overwrite former repeated values with the later unique values
 */
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int result = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[result] != nums[i])
            {
                result++;
                nums[result] = nums[i];
            }
        }

        return result + 1;
    }
};