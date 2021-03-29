/**
 * 74. 搜索二维矩阵
 * link：https://leetcode-cn.com/problems/search-a-2d-matrix/
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // int n = matrix.size();
        // int m = matrix[0].size();

        // A binary search tree rooted in the upper right corner
        // if (matrix[n - 1][m - 1] > target)
        // {
        //     int x = 0;
        //     int y = m - 1;
        //     while (x < n && y >= 0)
        //     {
        //         if (matrix[x][y] == target)
        //             return true;
        //         else if (matrix[x][y] > target)
        //             --y;
        //         else
        //             ++x;
        //     }
        //     return false;
        // }
        // return target == matrix[n - 1][m - 1];

        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
            return b < a[0];
        });
        if (row == matrix.begin())
            return false;

        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};