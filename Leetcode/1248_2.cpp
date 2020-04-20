/**
 * 1248. 统计「优美子数组」 前缀和+差分
 * link：https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 */

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> count(n + 1, 0);

        int result = 0;
        int odd_count = 0;
        for (int i = 0; i < n; i++)
        {
            odd_count += nums[i] & 1;
            result += odd_count >= k ? count[odd_count - k] : 0;
            count[odd_count] += 1;
        }

        return result;
    }
};

/* 
Before optimism

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int odd_num = 0;
        vector<int> before;
        int count = 0;
        for (auto &num : nums)
        {
            count++;
            if (num % 2)
            {
                before.push_back(count);
                odd_num++;
                count = 0;
            }
        }
        before.push_back(count + 1);
        int low = 0;
        int result = 0;
        for (int i = 0; i + k < before.size(); i++)
        {
            result += before[i] * before[i + k];
        }

        return result;
    }
};
 */