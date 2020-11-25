/**
 * 164. 最大间距
 * link：https://leetcode-cn.com/problems/maximum-gap/
 */

/**
 * The average difference between each sorted adjacent number is d = (max-min)/(n-1),
 * so the answer must >= d
 * We assign each number to a bucket of capacity d and totally (max-min)/d + 1 buckets
 * the maximum gap must be in the adjacent basket with elements
 */

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        int bucketW = max(1, (maxVal - minVal) / (n - 1));
        int bucketN = (maxVal - minVal) / bucketW + 1;

        vector<pair<int, int>> bucket(bucketN, {-1, -1});
        for (int i = 0; i < n; i++)
        {
            int index = (nums[i] - minVal) / bucketW;
            if (bucket[index].first == -1)
                bucket[index].first = nums[i];
            else
                bucket[index].first = min(bucket[index].first, nums[i]);
            bucket[index].second = max(bucket[index].second, nums[i]);
        }

        int result = 0;
        int last = -1;
        for (int i = 0; i < bucketN; i++)
        {
            if (bucket[i].first == -1)
                continue;
            if (last != -1)
                result = max(result, bucket[i].first - bucket[last].second);
            last = i;
        }
        return result;
    }
};