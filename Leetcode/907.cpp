/**
 * 907. 子数组的最小值之和
 * link：https://leetcode.cn/problems/sum-of-subarray-minimums/
 */

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int mod = 1000000007;
        const int n = arr.size();

        vector<int> left(n), right(n);
        vector<int> monoStack;
        for (int i = 0; i < n; i++)
        {
            while (!monoStack.empty() && arr[monoStack.back()] >= arr[i])
            {
                monoStack.pop_back();
            }
            left[i] = monoStack.empty() ? (i + 1) : (i - monoStack.back());
            monoStack.emplace_back(i);
        }
        monoStack.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!monoStack.empty() && arr[monoStack.back()] > arr[i])
            {
                monoStack.pop_back();
            }
            right[i] = monoStack.empty() ? (n - i) : (monoStack.back() - i);
            monoStack.emplace_back(i);
        }
        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            result = (result + ((long long)left[i] * right[i] * arr[i])) % mod;
        }
        return result;
    }
};