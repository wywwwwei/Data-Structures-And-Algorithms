/**
 * 75. 颜色分类
 * link：https://leetcode-cn.com/problems/sort-colors/
 */

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int begin = 0;
        int end = nums.size() - 1;

        int i = 0;
        while (i <= end)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[begin++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[end--]);
                continue;
            }
            i++;
        }
    }
};