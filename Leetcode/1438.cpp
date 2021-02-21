/**
 * 1438. 绝对差不超过限制的最长连续子数组   
 * link：https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 */

/**
 * continuous-subarray -> sliding windows
 * absolute diff less than or equal to limit    -> maximum value and minimum value in the window    -> ordered structure / monotonic queue
 */

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int n = nums.size();

        deque<int> maxVal, minVal;
        int left = 0, right = 0;
        int result = 0;
        while (right < n)
        {
            while (!maxVal.empty() && maxVal.back() < nums[right])
                maxVal.pop_back();
            while (!minVal.empty() && minVal.back() > nums[right])
                minVal.pop_back();

            maxVal.push_back(nums[right]);
            minVal.push_back(nums[right]);

            while (!maxVal.empty() && !minVal.empty() && (maxVal.front() - minVal.front()) > limit)
            {
                if (nums[left] == maxVal.front())
                    maxVal.pop_front();
                if (nums[left] == minVal.front())
                    minVal.pop_front();
                ++left;
            }

            result = max(result, right - left + 1);
            ++right;
        }

        return result;
    }
};