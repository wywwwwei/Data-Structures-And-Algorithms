/**
 * 912. 排序数组  Bucket Sort O(n + r)
 * link：https://leetcode-cn.com/problems/sort-an-array/
 */

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        bucketSort(nums, 2);
        return nums;
    }

    void bucketSort(vector<int> &nums, int bucket_size)
    {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (const auto &num : nums)
        {
            min_val = min(num, min_val);
            max_val = max(num, max_val);
        }
        int diff = max_val - min_val + 1;
        int bucket_nums = (diff % bucket_size == 0 ? diff / bucket_size : diff / bucket_size + 1);

        vector<int> buckets[bucket_nums];
        for (auto &num : nums)
        {
            int bucket_index = (num - min_val) / bucket_size;
            buckets[bucket_index].push_back(num);
        }

        int index = 0;
        for (auto &bucket : buckets)
        {
            if (bucket.size() > 0)
            {
                sort(bucket.begin(), bucket.end());
                for (auto &num : bucket)
                {
                    nums[index++] = num;
                }
            }
        }
    }
};