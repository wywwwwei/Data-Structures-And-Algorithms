/**
 * 912. 排序数组  Radix Sort
 * link：https://leetcode-cn.com/problems/sort-an-array/
 */

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        for (const auto &num : nums)
        {
            max_val = max(num, max_val);
            min_val = min(num, min_val);
        }
        int diff = min_val < 0 ? -min_val : 0;
        if (diff > 0)
        {
            for (auto &num : nums)
            {
                num += diff;
                max_val = max(num, max_val);
            }
        }

        vector<int> temp(nums.size(), 0);
        for (int exp = 1; max_val / exp > 0; exp *= 10)
        {
            RadixSort(nums, temp, exp);
        }

        if (diff > 0)
        {
            for (auto &num : nums)
                num -= diff;
        }
        return nums;
    }

    void RadixSort(vector<int> &nums, vector<int> &temp, int exp)
    {
        int count[10] = {0};

        for (int i = 0; i < nums.size(); i++)
        {
            temp[i] = nums[i];
        }

        for (const auto &num : nums)
        {
            count[(num / exp) % 10]++;
        }

        for (int i = 0; i < 9; i++)
        {
            count[i + 1] += count[i];
        }

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int tmp = (temp[i] / exp) % 10;
            nums[count[tmp] - 1] = temp[i];
            count[tmp]--;
        }
    }
};