/**
 * 566. 重塑矩阵
 * link：https://leetcode-cn.com/problems/reshape-the-matrix/
 */

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int m = nums.size();
        int n = nums[0].size();

        if (m * n != r * c)
            return nums;

        vector<vector<int>> result(r, vector<int>(c));
        int count = 0;
        for (auto &numbers : nums)
            for (auto num : numbers)
                result[count / c][count++ % c] = num;

        return result;
    }
};