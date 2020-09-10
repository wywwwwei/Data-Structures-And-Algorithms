/**
 * 78. 子集 Binary Sorted
 * link：https://leetcode-cn.com/problems/subsets/
 */

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();

        for (unsigned int i = 0; i < 1 << n; i++)
        {
            vector<int> cur;
            int count = (i > 0 ? __builtin_ctz(i) : 0);
            unsigned int mask = 1 << count;
            while (count < n)
            {
                if (i & mask)
                    cur.push_back(nums[count]);
                mask = mask << 1;
                count++;
            }
            result.push_back(cur);
        }
        return result;
    }
};