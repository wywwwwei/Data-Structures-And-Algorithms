/**
 * 287. 寻找重复数
 * link：https://leetcode-cn.com/problems/find-the-duplicate-number/
 */

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 1;
        int right = nums.size() - 1;
        int mid = 0;
        int count = 0;

        while (left < right)
        {
            mid = (left + right) / 2;
            count = 0;
            for (auto &num : nums)
                if (num <= mid)
                    count++;
            if (count <= mid)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};