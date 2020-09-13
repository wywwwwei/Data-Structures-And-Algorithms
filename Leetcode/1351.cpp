/**
 * 1351. 统计有序矩阵中的负数
 * link：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix/
 */

/**
 * Because grid is sorted in non-increasing order both row-wise and column-wise,
 * the negative numbers must be in the lower right part.
 * 
 * So we start search in the top right corner.
 * e.g.
 * + + + + - 
 * + + + -
 * + - -
 * + -
 * -
 * Assume that we're in row i, column j
 * if grid[i][j] <= 0, count += the remaining rows + 1(current row), j--
 * else i++
 */

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int result = 0;
        for (int i = 0, j = n - 1; i < m && j >= 0;)
        {
            if (grid[i][j] >= 0)
            {
                i++;
            }
            else
            {
                result += m - i;
                j--;
            }
        }

        return result;
    }
};