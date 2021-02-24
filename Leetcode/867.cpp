/**
 * 867. 转置矩阵
 * link：https://leetcode-cn.com/problems/transpose-matrix/
 */

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // if (m == n) // the square matrix flips directly
        // {
        //     for (int i = 0; i < m; ++i)
        //         for (int j = 0; j < i; ++j)
        //             swap(matrix[i][j], matrix[j][i]);
        //     return matrix;
        // }

        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                result[i][j] = matrix[j][i];

        return result;
    }
};