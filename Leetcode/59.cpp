/**
 * 59. 螺旋矩阵 II
 * link：https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> result(n, vector<int>(n));

        int count = 0;
        for (int i = 0; i < (n + 1) / 2; ++i)
        {
            for (int j = i; j < n - i; ++j)
                result[i][j] = ++count;

            for (int j = i + 1; j < n - i; ++j)
                result[j][n - i - 1] = ++count;

            if (i >= n - i - 1) // top row and bottom row are the same or left column and right column are the same
                break;

            for (int j = n - i - 2; j >= i; --j)
                result[n - 1 - i][j] = ++count;

            for (int j = n - 2 - i; j > i; --j)
                result[j][i] = ++count;
        }

        return result;
    }
};