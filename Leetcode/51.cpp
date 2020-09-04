/**
 * 51. N 皇后
 * link：https://leetcode-cn.com/problems/n-queens/
 */

/**
 *  x & (-x)        ->  lowbit(x)   ->  one of possible position
 *  x & (x - 1)     ->  zero the low bit    -> remove one possible position
 */

class Solution
{
    vector<vector<string>> result;
    vector<int> queens;
    int number;

public:
    vector<vector<string>> solveNQueens(int n)
    {
        queens.resize(n, -1);
        number = n;
        solve(0, 0, 0, 0);
        return result;
    }

    void solve(int row, int columns, int left_diag, int right_diag)
    {
        if (row == number)
        {
            auto board = int2str(queens);
            result.push_back(board);
        }
        else
        {
            int all_pos = ((1 << number) - 1) & (~(columns | left_diag | right_diag));
            while (all_pos != 0)
            {
                int pos = all_pos & (-all_pos);
                all_pos = all_pos & (all_pos - 1);
                int column = __builtin_ctz(pos);
                queens[row] = column;
                solve(row + 1, columns | pos, (left_diag | pos) >> 1, (right_diag | pos) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> int2str(vector<int> &queens)
    {
        vector<string> board;
        for (int i = 0; i < number; i++)
        {
            string row = string(number, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};