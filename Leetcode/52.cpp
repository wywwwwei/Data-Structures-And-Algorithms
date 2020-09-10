/**
 * 52. N皇后 II
 * link：https://leetcode-cn.com/problems/n-queens-ii/
 */

/**
 * Concrete solution:
 * 51. N 皇后
 * link: https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-by-leetcode-solution/
 */

class Solution
{
    int count = 0;
    int target;

public:
    int totalNQueens(int n)
    {
        target = n;
        solve(0, 0, 0, 0);
        return count;
    }

    void solve(int row, int columns, int left_diag, int right_diag)
    {
        if (row == target)
        {
            count++;
            return;
        }
        else
        {
            int all_pos = ((1 << target) - 1) & (~(columns | left_diag | right_diag));
            while (all_pos != 0)
            {
                int pos = all_pos & (-all_pos);
                all_pos = all_pos & (all_pos - 1);
                solve(row + 1, columns | pos, (left_diag | pos) >> 1, (right_diag | pos) << 1);
            }
        }
    }
};