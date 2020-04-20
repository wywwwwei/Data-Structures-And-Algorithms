/**
 * 1248. 统计「优美子数组」 双指针
 * link：https://leetcode-cn.com/problems/count-number-of-nice-subarrays/
 */

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int low_index = -1;
        int high_index = -1;
        int odd_count = 0;
        int all_count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2)
                odd_count++;
            if (odd_count == 1 && low_index == -1)
                low_index = all_count;
            if (odd_count == k && high_index == -1)
            {
                high_index = all_count;
                break;
            }
            all_count++;
        }

        if (high_index == -1)
            return 0;

        int result = 0;
        int low_count = low_index + 1;
        int high_count = 1;

        while (high_index < nums.size())
        {
            high_index += 1;
            while (high_index < nums.size())
            {
                if (nums[high_index] % 2)
                    break;
                else
                    high_count++;
                high_index++;
            }
            result += low_count * high_count;
            low_count = 1;
            high_count = 1;
            low_index++;
            while (low_index < nums.size() && nums[low_index] % 2 == 0)
            {
                low_index++;
                low_count++;
            }
        }

        return result;
    }
};