/**
 * 15. 三数之和
 * link：https://leetcode-cn.com/problems/3sum/
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];
            int right = n - 1;
            for (int left = i + 1; left < n; left++)
            {
                if (left > i + 1 && nums[left] == nums[left - 1])
                    continue;

                while (left < right && nums[left] + nums[right] > target)
                    right--;

                if (left == right)
                    break;

                if (nums[left] + nums[right] == target)
                    result.push_back({nums[i], nums[left], nums[right]});
            }
        }

        return result;
    }
};