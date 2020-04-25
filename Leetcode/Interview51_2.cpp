/**
 * 面试题51. 数组中的逆序对 MergeSort
 * link：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

class Solution
{
    int MergeSort(vector<int> &nums, vector<int> &aux, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;

        int result = MergeSort(nums, aux, left, mid) + MergeSort(nums, aux, mid + 1, right);

        int idx = left;
        int low = left, high = mid + 1;
        while (low <= mid && high <= right)
        {
            if (nums[low] <= nums[high])
            {
                aux[idx++] = nums[low++];
                result += high - mid - 1;
            }
            else
            {
                aux[idx++] = nums[high++];
            }
        }

        while (low <= mid)
        {
            aux[idx++] = nums[low++];
            result += right - mid;
        }
        while (high <= right)
        {
            aux[idx++] = nums[high++];
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = aux[i];
        }
        return result;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> aux(nums.size());
        return MergeSort(nums, aux, 0, nums.size() - 1);
    }
};