/**
 * 304. 二维区域和检索 - 矩阵不可变
 * link：https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 */

class NumMatrix
{
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m <= 0)
            return;

        int n = matrix[0].size();
        sums.resize(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + matrix[i][j];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2 + 1][col2 + 1] + sums[row1][col1] - sums[row2 + 1][col1] - sums[row1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */