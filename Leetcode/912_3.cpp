/**
 * 912. 排序数组  Merge Sort O(N log N)
 * link：https://leetcode-cn.com/problems/sort-an-array/
 */

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> temp(nums.size(), 0);
        merge(nums, temp, 0, nums.size() - 1);
        return nums;
    }

    void merge(vector<int> &nums, vector<int> &temp, int low, int high)
    {
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;

        merge(nums, temp, low, mid);
        merge(nums, temp, mid + 1, high);

        mergeSort(nums, temp, low, mid, high);
    }

    void mergeSort(vector<int> &nums, vector<int> &temp, int low, int mid, int high)
    {
        for (int i = low; i <= high; i++)
        {
            temp[i] = nums[i];
        }

        int nums_index = low;
        int index1 = low;
        int index2 = mid + 1;
        while (index1 <= mid && index2 <= high)
        {
            if (temp[index1] < temp[index2])
            {
                nums[nums_index++] = temp[index1];
                index1++;
            }
            else
            {
                nums[nums_index++] = temp[index2];
                index2++;
            }
        }
        while (index1 <= mid)
        {
            nums[nums_index++] = temp[index1++];
        }
        while (index2 <= high)
        {
            nums[nums_index++] = temp[index2++];
        }
    }
};