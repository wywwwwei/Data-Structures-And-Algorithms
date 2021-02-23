/**
 * 832. 翻转图像
 * link：https://leetcode-cn.com/problems/flipping-an-image/
 */

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int m = A.size();
        int n = A[0].size();

        bool reverse = (n % 2 == 1);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                A[i][j] = 1 - A[i][j];
                A[i][n - 1 - j] = 1 - A[i][n - 1 - j];
                swap(A[i][j], A[i][n - 1 - j]);
            }
            if (reverse)
                A[i][n / 2] = 1 - A[i][n / 2];
        }

        return A;
    }
};