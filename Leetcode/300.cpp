/**
 * 300. 最长上升子序列 dp + 二分搜索
 * link：https://leetcode-cn.com/problems/longest-increasing-subsequence/
 */

/**
 * We can just use dynamic programming to solve this problem.
 * dp[i] = max(dp[i], dp[i-k] + 1)
 * but for k, we need O (N) time each time to get the answer,
 * so the overall time complexity is O(N^2)
 * 
 * But by observing the state transition equation above, 
 * our traversal can actually be simplified, as long as we record max(dp[<i])
 * At the same time max(dp[<i]) can be used on the premise that nums[i] > nums[<i].
 * At this point, it doesn't matter which element is currently traversed.
 * 
 * So we set dp[i] = the last value of longest increasing subsequence when its length is i
 * and try to keep this value as small as possible, which means it is easier to increase
 * State transition equation
 * when nums[i] > dp.back() = max(dp), dp.push_back(nums[i])
 * when nums[i] <= dp.back() = max(dp), find the first element larger than it and replace it.
 * dp is ordered, so we use binary search here
 * time complexity O(Nlog(N))
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int nums_size = nums.size();
        if (nums_size == 0)
            return 0;

        vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < nums_size; i++)
        {
            if (nums[i] > dp.back())
                dp.push_back(nums[i]);
            else
                //dp[binarySearch(dp, 0, dp.size() - 1, nums[i])] = nums[i];
                dp[lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin()] = nums[i];
        }

        return dp.size();
    }

    int binarySearch(vector<int> &dp, int low, int high, int target)
    {
        if (low == high)
        {
            if (dp[low] >= target)
                return low;
            else
                return 0;
        }
        int mid = (low + high) / 2;
        if (dp[mid] >= target)
            return binarySearch(dp, low, mid, target);
        else
            return binarySearch(dp, mid + 1, high, target);
    }
};