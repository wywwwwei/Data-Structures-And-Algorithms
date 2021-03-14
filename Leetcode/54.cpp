/**
 * 54. 螺旋矩阵
 * link：https://leetcode-cn.com/problems/spiral-matrix/
 */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result(m * n);
        int count = 0;
        for (int i = 0; i < (min(m, n) + 1) / 2; ++i)
        {
            for (int j = i; j < n - i; ++j)
                result[count++] = matrix[i][j];

            for (int j = i + 1; j < m - i; ++j)
                result[count++] = matrix[j][n - i - 1];

            if (i >= n - i - 1 || i >= m - i - 1)   // top row and bottom row are the same or left column and right column are the same
                break;

            for (int j = n - i - 2; j >= i; --j)
                result[count++] = matrix[m - 1 - i][j];

            for (int j = m - 2 - i; j > i; --j)
                result[count++] = matrix[j][i];
        }

        return result;
    }
};