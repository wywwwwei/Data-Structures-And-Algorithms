/**
 * 37. 解数独 状态压缩+回溯
 * link：https://leetcode-cn.com/problems/sudoku-solver/
 */

class Solution
{
    using Kv = pair<int, int>;
    int row[9];
    int col[9];
    int block[3][3];
    vector<Kv> all_pos;

public:
    void reversePos(int i, int j, int val)
    {
        row[i] ^= 1 << val;
        col[j] ^= 1 << val;
        block[i / 3][j / 3] ^= 1 << val;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    reversePos(i, j, board[i][j] - '0' - 1);
                }
                else
                {
                    all_pos.push_back({i, j});
                }
            }
        }
        dfs(board, 0);
    }

    bool dfs(vector<vector<char>> &board, int index)
    {
        if (index == all_pos.size())
            return true;

        Kv &pos = all_pos[index];
        int selection = 0x1FF & ~(row[pos.first] | col[pos.second] | block[pos.first / 3][pos.second / 3]);
        while (selection != 0)
        {
            int cur_select = selection & (-selection);
            selection = selection & (selection - 1);
            int fill_val = __builtin_ctz(cur_select);

            reversePos(pos.first, pos.second, fill_val);
            board[pos.first][pos.second] = '0' + fill_val + 1;
            if (dfs(board, index + 1))
                return true;
            reversePos(pos.first, pos.second, fill_val);
        }

        return false;
    }
};