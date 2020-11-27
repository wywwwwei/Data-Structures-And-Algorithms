/**
 * 493. 翻转对  Merge Sort
 * link：https://leetcode-cn.com/problems/reverse-pairs/
 */

class Solution
{
    using ll = long long;

    vector<int> tmp;
    int mergeSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int result = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);

        int l = left, r = mid + 1;
        while (l <= mid)
        {
            while (r <= right && (ll)nums[l] > 2 * (ll)nums[r])
                r++;
            l++;
            result += r - mid - 1;
        }

        l = left, r = mid + 1;
        int count = left;
        while (l <= mid && r <= right)
        {
            if (nums[l] <= nums[r])
                tmp[count++] = nums[l++];
            else
                tmp[count++] = nums[r++];
        }
        while (l <= mid)
            tmp[count++] = nums[l++];
        while (r <= right)
            tmp[count++] = nums[r++];

        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
        return result;
    }

public:
    int reversePairs(vector<int> &nums)
    {
        tmp.resize(nums.size());
        return mergeSort(nums, 0, nums.size() - 1);
    }
};