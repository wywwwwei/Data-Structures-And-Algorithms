/**
 * 1636. 按照频率将数组升序排序
 * link：https://leetcode-cn.com/problems/sort-array-by-increasing-frequency/
 */

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        int count[201] = {0};
        for (const int &num : nums)
            count[num + 100]++;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = 1000 * count[nums[i] + 100] + 100 - nums[i];
        sort(nums.begin(), nums.end());
        for (int &num : nums)
            num = 100 - (num % 1000);
        return nums;
    }
};