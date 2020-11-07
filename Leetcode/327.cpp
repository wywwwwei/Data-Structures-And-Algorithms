/**
 * 327. 区间和的个数
 * link：https://leetcode-cn.com/problems/count-of-range-sum/
 */

/**
 * Merge Sort
 * 
 * According to the question, we need find the range sum that corresponding to
 * lower <= nums[i] + nums[i+1] + ... + nums[j] <= upper
 * which is equivalent to
 * lower <= prefix_sum[j] - prefix_sum[i] <= upper
 * 
 * However, for the unordered prefix_sum, the time complexity is still O(n^2)
 * but for locally ordered ones such as two ordered parts in merge sort
 * prefix_sum[left]...prefix_sum[mid]
 * prefix_sum[mid+1]...prefix_sum[right]
 * 
 * Then we can find out the solution j in [mid+1,right] for all i in [left,mid] by double pointers -> O(N)
 */

class Solution
{
    int lower_;
    int upper_;
    vector<long> tmp;

    int mergeSort(vector<long> &sum, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(sum, left, mid) + mergeSort(sum, mid + 1, right);

        int count = left;
        int l = mid + 1;
        int r = mid + 1;
        while (count <= mid && l <= right)
        {
            while (l <= right && sum[l] - sum[count] < lower_)
                l++;
            while (r <= right && sum[r] - sum[count] <= upper_)
                r++;
            res += r - l;
            count++;
        }

        count = left;
        l = left;
        r = mid + 1;
        while (l <= mid && r <= right)
        {
            if (sum[l] <= sum[r])
                tmp[count++] = sum[l++];
            else
                tmp[count++] = sum[r++];
        }
        while (l <= mid)
            tmp[count++] = sum[l++];
        while (r <= right)
            tmp[count++] = sum[r++];

        copy(tmp.begin() + left, tmp.begin() + right + 1, sum.begin() + left);
        return res;
    }

public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        lower_ = lower;
        upper_ = upper;

        int n = nums.size();
        long sum = 0;
        vector<long> preSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            preSum[i] = sum;
            sum += nums[i];
        }
        preSum[n] = sum;

        tmp.resize(n + 1, 0);
        return mergeSort(preSum, 0, n);
    }
};