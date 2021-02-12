/**
 * 448. 找到所有数组中消失的数字
 * link：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 */

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();

        // without extra space -> in-place modification as a hash table
        for (int num : nums)
            nums[(num - 1) % n] += n;       // overflow?

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                result.emplace_back(i + 1);

        return result;
    }
};