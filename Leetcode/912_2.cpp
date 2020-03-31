/**
 * 912. 排序数组  Shellsort Time complexity is dependent on the gap sequence it uses.
 * link：https://leetcode-cn.com/problems/sort-an-array/
 */

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        for (int gap = nums.size() / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < nums.size(); i++)
            {
                int record = nums[i];
                int j;
                for (j = i; j >= gap && nums[j - gap] > record; j -= gap)
                    nums[j] = nums[j - gap];
                nums[j] = record;
            }
        }
        return nums;
    }
};