/**
 * 912. 排序数组  快排(O(N log N))
 * link：https://leetcode-cn.com/problems/sort-an-array/
 */

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        srand((unsigned)time(NULL));
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

    int randomized_partition(vector<int> &nums, int low, int high)
    {
        int i = rand() % (high - low + 1) + low;
        swap(nums[high], nums[i]);

        int pivot = nums[high];

        int index = low;
        for (int i = low; i < high; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[high]);

        return index;
    }

    void quicksort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;

        int index = randomized_partition(nums, low, high);

        quicksort(nums, low, index - 1);
        quicksort(nums, index + 1, high);
    }
};