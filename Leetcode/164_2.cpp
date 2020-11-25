/**
 * 164. 最大间距    Radix Sort
 * link：https://leetcode-cn.com/problems/maximum-gap/
 */

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;

        vector<int> buf(n);
        int count[10];
        int maxVal = *max_element(nums.begin(), nums.end());
        int radix = 1;
        while (maxVal >= radix)
        {
            fill(count, count + 10, 0);
            for (int i = 0; i < n; i++)
                count[(nums[i] / radix) % 10]++;
            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];
            for (int i = n - 1; i >= 0; i--)
                buf[(count[(nums[i] / radix) % 10]--) - 1] = nums[i];
            copy(buf.begin(), buf.end(), nums.begin());
            radix *= 10;
        }

        int result = 0;
        for (int i = 1; i < n; i++)
            result = max(result, nums[i] - nums[i - 1]);

        return result;
    }
};