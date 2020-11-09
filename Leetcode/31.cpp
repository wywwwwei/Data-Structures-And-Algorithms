/**
 * 31. 下一个排列
 * link：https://leetcode-cn.com/problems/next-permutation/
 */

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        int index = n - 2;
        while (index >= 0 && nums[index] >= nums[index + 1])
            index--;
        if (index >= 0)
        {
            for (int i = n - 1; i > index; i--)
            {
                if (nums[i] > nums[index])
                {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }

        for (int l = index + 1, r = n - 1; l < r; l++, r--)
        {
            swap(nums[l], nums[r]);
        }
    }
};