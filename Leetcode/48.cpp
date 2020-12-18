/**
 * 48. 旋转图像
 * link：https://leetcode-cn.com/problems/rotate-image/
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // for (int i = 0; i < n / 2; ++i)
        // {
        //     for (int j = 0; j < (n + 1) / 2; ++j)
        //     {
        //         int temp = matrix[i][j];
        //         matrix[i][j] = matrix[n - j - 1][i];
        //         matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        //         matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        //         matrix[j][n - i - 1] = temp;
        //     }
        // }

        for (int i = 0; i < n / 2; i++)
            for (int j = 0; j < n; j++)
                swap(matrix[i][j], matrix[n - i - 1][j]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
};