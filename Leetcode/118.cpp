/**
 * 118. 杨辉三角
 * link：https://leetcode-cn.com/problems/pascals-triangle/
 */

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; i++)
        {
            auto &cur = result[i];
            cur.resize(i + 1);
            cur[0] = 1;
            cur[i] = 1;
            for (int j = 1; j < i; j++)
                cur[j] = result[i - 1][j - 1] + result[i - 1][j];
        }

        return result;
    }
};