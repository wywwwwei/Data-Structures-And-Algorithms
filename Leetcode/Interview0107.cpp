/**
 * 面试题 01.07. 旋转矩阵
 * link：https://leetcode-cn.com/problems/rotate-matrix-lcci/
 */

/**
 * temp                     = matrix[row][col]
 * matrix[row][col]         = matrix[n−col−1][row]
 * matrix[n−col−1][row]     = matrix[n−row−1][n−col−1]
 * matrix[n−row−1][n−col−1] = matrix[col][n-row-1]
 * matrix[col][n-row-1]     = temp;
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};